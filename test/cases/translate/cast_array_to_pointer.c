void foo(void) {
    int a[10];
    int* x = a;

    char b[6];
    char* y = b;
}

// translate
//
// pub export fn foo() void {
//     var a: [10]c_int = undefined;
//     _ = &a;
//     var x: [*c]c_int = @ptrCast(@alignCast(&a));
//     _ = &x;
//     var b: [6]c_char = undefined;
//     _ = &b;
//     var y: [*c]c_char = @ptrCast(@alignCast(&b));
//     _ = &y;
// }
