void foo(void) {
    static const unsigned char v2[] = "2.2.2";
}

// translate
//
// pub export fn foo() void {
//     const static_local_v2 = struct {
//         const v2: [6]u8 = @as(*const [6]u8, @ptrCast("2.2.2")).*;
//     };
//     _ = &static_local_v2;
// }
