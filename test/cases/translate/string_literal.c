char s[] = "World";
unsigned char u[] = "World";
signed char *sp = "World";
unsigned char *up = "World";

int bar(void) {
    return s[0] + u[0] + sp[0] + up[0];
}

char *p1 = "bar";
char *a1[2] = { "r<=", "r=" };
char a2[2][4] = { "r<=", "r=" };

const char *s1 = (const char []){"abc"};
const char *s2 = (const char [3]){"abc"};

// translate
//
// pub export var s: [6]c_char = @as(*const [6]c_char, @ptrCast("World")).*;
// pub export var u: [6]u8 = @as(*const [6]u8, @ptrCast("World")).*;
// pub export var sp: [*c]i8 = @constCast(@as(*const [5:0]i8, @ptrCast("World")));
// pub export var up: [*c]u8 = @constCast("World");
// pub export fn bar() c_int {
//     return ((@as(c_int, s[0]) + @as(c_int, u[0])) + @as(c_int, sp[0])) + @as(c_int, up[0]);
// }
//
// pub export var p1: [*c]c_char = @constCast(@as(*const [3:0]c_char, @ptrCast("bar")));
// pub export var a1: [2][*c]c_char = [2][*c]c_char{
//     @constCast(@as(*const [3:0]c_char, @ptrCast("r<="))),
//     @constCast(@as(*const [2:0]c_char, @ptrCast("r="))),
// };
// pub export var a2: [2][4]c_char = [2][4]c_char{
//     @as(*const [4]c_char, @ptrCast("r<=")).*,
//     @as(*const [2:0]c_char, @ptrCast("r="))[0..2].* ++ @as([2]c_char, @splat(0)),
// };
//
// pub export var s1: [*c]const c_char = @ptrCast(@alignCast(&@as([4]c_char, @as(*const [4]c_char, @ptrCast("abc")).*)));
// pub export var s2: [*c]const c_char = @ptrCast(@alignCast(&@as([3]c_char, @as(*const [3:0]c_char, @ptrCast("abc")).*)));
