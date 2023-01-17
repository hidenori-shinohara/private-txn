pragma circom 2.0.0;

function commit(m, r) {
    // A very silly commit function
    return m + r;
}

template Multiplier2() {
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
    c3 <== r1*r2 + r3 + fee;
 }

 component main = Multiplier2();


// pragma circom 2.0.0;
// 
// function commit(m, r) {
//     // A very silly commit function
//     return m + r;
// }
// 
// function nonneg(m) {
//     if (m >= 0)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// 
// template PrivateTxn() {
//     signal input m1;
//     signal input r1;
//     signal input m2;
//     signal input r2;
//     signal input m3;
//     signal input r3;
//     signal input fee;
//     signal output c1;
//     signal output c2;
//     signal output c3;
//     c1 <== commit(m1, r1);
//     //c2 <== commit(m2, r2);
//     //c3 <== commit(m3, r3);
//     //m1 === m2 + m3 + fee;
//     // I have no idea, but this doesn't compile.
//     // I'll ignore this for now and fix it later.
//     // sign2 = nonneg(m2);
//     // sign3 = nonneg(m3);
// }
// 
// component main = PrivateTxn();
