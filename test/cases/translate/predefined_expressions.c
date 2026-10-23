void foo(void) {
    __func__;
    __FUNCTION__;
    __PRETTY_FUNCTION__;
}

// translate
//
// pub export fn foo() void {
//     const static_local___PRETTY_FUNCTION__ = struct {
//         const __PRETTY_FUNCTION__: [14:0]c_char = @as(*const [14:0]c_char, @ptrCast("void foo(void)")).*;
//     };
//     _ = &static_local___PRETTY_FUNCTION__;
//     const static_local___func__ = struct {
//         const __func__: [3:0]c_char = @as(*const [3:0]c_char, @ptrCast("foo")).*;
//     };
//     _ = &static_local___func__;
//     _ = static_local___func__.__func__;
//     _ = static_local___func__.__func__;
//     _ = static_local___PRETTY_FUNCTION__.__PRETTY_FUNCTION__;
// }
