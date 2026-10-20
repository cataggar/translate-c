typedef char* yes;
void foo(void) {
    yes a;
    if (a) 2;
    if (foo) 3;
}

// translate
//
// pub const yes = [*c]u8;
// pub export fn foo() void {
//     var a: yes = undefined;
//     _ = &a;
//     if (a != null) {
//         _ = 2;
//     }
//     if (@intFromPtr(&foo) != 0) {
//         _ = 3;
//     }
// }
