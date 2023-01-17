# Private Txn

Bad implementation of ideas from [this YouTube video](https://youtu.be/H3GmsxRU1Kw?t=3311)

Idea: It's like Bitcoin, but the amount sent is private. The sender and recipient are public.

# Prereqs

Install Circom and Snarkjs.

# How does that work?

- `private-txn.circom` specifies the circuit.
  One can treat this as a black box.
- `input.json` specifies the input.
    - Suppose A wants to send B some money.
    - `m1` is the amount A current has.
    - `m2` is the amount that A wants to give B. 
    - `m3` is the amount that A will have after the transaction and fee.
    - `fee` is the transaction fee that A pays.
    - `r1`, `r2`, and `r3` are secret nonces A and B share.
    - Note that A and B will keep `m{1, 2, 3}` and `r{1, 2, 3}` private.

For instance, `input.json` may contain

```
{ "m1": "100", "r1": "99999", "m2": "80", "r2": "12345", "m3": "15", "r3": "909090", "fee": "5"}
```

This means A has 100 dollars and sends 80 dollars to B.
The transaction fee is 5, so A has 15 dollars left.
For random nonces, A picked 99999, 12345, and 909090.
The first step is to turn this input file into a witness.
I think this is just turning a JSON file into a more machine readable format, but I'm not 100% sure.

The next step is to set up a trusted environment and generate the proof.

Run `make compile-circuit  && make compile-witness && make trusted-setup && make generate-proof`
Then we'll have many output files.

- Each `(m_i, r_i)` generates a `com_i` as specified in the video.
  I believe that this should utilize some real crptographic function.
  However, for this demo, I simply added `m_i + r_i`.
  You can see that `public.json` contains `com_1`, `com_2`, and `com_3`.
  With the example above, you'll get:
- You need to send `public.json` to whoever wants to verify your transaction.
  Also, you need to send `verification_key.json` and `proof.json`.
  `proof.json` is obviously the proof.
  `verification_key.json` is *probably* the variables that specify the verification algorithm.
  But I'm not certain.


```
$ cat public.json 
[
 "100099",
 "12425",
 "909105"
]
```


