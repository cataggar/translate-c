extern unsigned char arr0[] = "hello";
static unsigned char arr1[] = "hello";
unsigned char arr2[] = "hello";

// translate
//
// pub export var arr0: [6]u8 = @as(*const [6]u8, @ptrCast("hello")).*;
// pub var arr1: [6]u8 = @as(*const [6]u8, @ptrCast("hello")).*;
// pub export var arr2: [6]u8 = @as(*const [6]u8, @ptrCast("hello")).*;
