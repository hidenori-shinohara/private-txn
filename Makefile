compile-circuit:
	circom private-txn.circom --r1cs --wasm --sym --c
compile-witness:
	node private-txn_js/generate_witness.js private-txn_js/private-txn.wasm input.json witness.wtns
trusted-setup:
	snarkjs powersoftau new bn128 12 pot12_0000.ptau -v
	snarkjs powersoftau contribute pot12_0000.ptau pot12_0001.ptau --name="First contribution" -v
	snarkjs powersoftau prepare phase2 pot12_0001.ptau pot12_final.ptau -v
	snarkjs groth16 setup private-txn.r1cs pot12_final.ptau private-txn_0000.zkey
	snarkjs zkey contribute private-txn_0000.zkey private-txn_0000.zkey --name="1st Contributor Name" -v
	snarkjs zkey export verificationkey private-txn_0000.zkey verification_key.json
generate-proof:
	snarkjs groth16 prove private-txn_0000.zkey witness.wtns proof.json public.json
verify-proof:
	snarkjs groth16 verify verification_key.json public.json proof.json

