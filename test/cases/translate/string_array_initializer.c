static const char foo[] = {"bar"};

// translate
//
// pub const foo: [3:0]c_char = @as(*const [3:0]c_char, @ptrCast("bar")).*;
