char s[] = "World";
unsigned char u[] = "World";
signed char *sp = "World";
unsigned char *up = "World";

int bar(void) {
    return s[0] + u[0] + sp[0] + up[0];
}


// translate
//
// pub export var s: [5:0]c_char = @as(*const [5:0]c_char, @ptrCast("World")).*;
// pub export var u: [5:0]u8 = "World".*;
// pub export var sp: [*c]i8 = @constCast(@as(*const [5:0]i8, @ptrCast("World")));
// pub export var up: [*c]u8 = @constCast("World");
// pub export fn bar() c_int {
//     return ((@as(c_int, s[0]) + @as(c_int, u[0])) + @as(c_int, sp[0])) + @as(c_int, up[0]);
// }
