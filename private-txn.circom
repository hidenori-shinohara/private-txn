pragma circom 2.0.0;

function commit(m, r) {
    // A very silly commit function
    // I have no idea why,
    // but it seems important that we multiple 1.
    // It might have something to do with quadratic
    // vs linear polynomials.
    return 1 * m + r;
}

template PrivateTxn() {
    signal input m1;
    signal input r1;
    signal input m2;
    signal input r2;
    signal input m3;
    signal input r3;
    signal input fee;
    signal output c1;
    signal output c2;
    signal output c3;
    c1 <== commit(m1, r1);
    c2 <== commit(m2, r2);
    c3 <== commit(m3, r3);

    // * A has m1 dollars.
    // * A sends m2 dollars to B.
    // * A pays `fee` dollars in fees.
    // * A's remaining balance is m3 dollars.
    m1 === m2 + m3 + fee;


    // Make sure that m2 >= 0 && m3 >= 0
    signal sign2;
    sign2 <-- m2 >= 0 ? 1 : 0;
    signal sign3;
    sign3 <-- m3 >= 0 ? 1 : 0;
    (sign2 * sign3) === 1;
 }

 component main = PrivateTxn();

