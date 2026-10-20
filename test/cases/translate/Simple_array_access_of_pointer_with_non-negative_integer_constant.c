void foo(int *p) {
    p[0];
    p[1];
}

// translate
//
// pub export fn foo(arg_p: [*c]c_int) void {
//     var p = arg_p;
//     _ = &p;
//     _ = p[0];
//     _ = p[1];
// }
