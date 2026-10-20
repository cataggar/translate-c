int g;
unsigned char r;

int foo(void) {
    int x = 5;
    r = (g = (x > 0));
    return 0;
}

int bar(void) {
    int a = 10;
    int verify_compound = 0;

    a += 0b0101;
    verify_compound += (a == 15);

    return verify_compound;
}

// translate
//
// pub export var g: c_int = 0;
// pub export var r: u8 = 0;
// pub export fn foo() c_int {
//     var x: c_int = 5;
//     _ = &x;
//     r = @bitCast(@as(i8, @truncate(blk: {
//         const tmp = @as(c_int, @intFromBool(x > @as(c_int, 0)));
//         g = tmp;
//         break :blk tmp;
//     })));
//     return 0;
// }
// pub export fn bar() c_int {
//     var a: c_int = 10;
//     _ = &a;
//     var verify_compound: c_int = 0;
//     _ = &verify_compound;
//     a += 5;
//     verify_compound += @intFromBool(a == @as(c_int, 15));
//     return verify_compound;
// }
