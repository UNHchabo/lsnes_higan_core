#include "framebuffer.hpp"

namespace
{
	framebuffer::basecolor snow("snow", 0xfffafa);
	framebuffer::basecolor snow1("snow1", 0xfffafa);
	framebuffer::basecolor snow2("snow2", 0xeee9e9);
	framebuffer::basecolor rosybrown1("rosybrown1", 0xffc1c1);
	framebuffer::basecolor rosybrown2("rosybrown2", 0xeeb4b4);
	framebuffer::basecolor snow3("snow3", 0xcdc9c9);
	framebuffer::basecolor lightcoral("lightcoral", 0xf08080);
	framebuffer::basecolor indianred1("indianred1", 0xff6a6a);
	framebuffer::basecolor rosybrown3("rosybrown3", 0xcd9b9b);
	framebuffer::basecolor indianred2("indianred2", 0xee6363);
	framebuffer::basecolor rosybrown("rosybrown", 0xbc8f8f);
	framebuffer::basecolor brown1("brown1", 0xff4040);
	framebuffer::basecolor firebrick1("firebrick1", 0xff3030);
	framebuffer::basecolor brown2("brown2", 0xee3b3b);
	framebuffer::basecolor indianred("indianred", 0xcd5c5c);
	framebuffer::basecolor indianred3("indianred3", 0xcd5555);
	framebuffer::basecolor firebrick2("firebrick2", 0xee2c2c);
	framebuffer::basecolor snow4("snow4", 0x8b8989);
	framebuffer::basecolor brown3("brown3", 0xcd3333);
	framebuffer::basecolor red("red", 0xff0000);
	framebuffer::basecolor red1("red1", 0xff0000);
	framebuffer::basecolor rosybrown4("rosybrown4", 0x8b6969);
	framebuffer::basecolor firebrick3("firebrick3", 0xcd2626);
	framebuffer::basecolor red2("red2", 0xee0000);
	framebuffer::basecolor firebrick("firebrick", 0xb22222);
	framebuffer::basecolor brown("brown", 0xa52a2a);
	framebuffer::basecolor red3("red3", 0xcd0000);
	framebuffer::basecolor indianred4("indianred4", 0x8b3a3a);
	framebuffer::basecolor brown4("brown4", 0x8b2323);
	framebuffer::basecolor firebrick4("firebrick4", 0x8b1a1a);
	framebuffer::basecolor darkred("darkred", 0x8b0000);
	framebuffer::basecolor red4("red4", 0x8b0000);
	framebuffer::basecolor lightpink1("lightpink1", 0xffaeb9);
	framebuffer::basecolor lightpink3("lightpink3", 0xcd8c95);
	framebuffer::basecolor lightpink4("lightpink4", 0x8b5f65);
	framebuffer::basecolor lightpink2("lightpink2", 0xeea2ad);
	framebuffer::basecolor lightpink("lightpink", 0xffb6c1);
	framebuffer::basecolor pink("pink", 0xffc0cb);
	framebuffer::basecolor crimson("crimson", 0xdc143c);
	framebuffer::basecolor pink1("pink1", 0xffb5c5);
	framebuffer::basecolor pink2("pink2", 0xeea9b8);
	framebuffer::basecolor pink3("pink3", 0xcd919e);
	framebuffer::basecolor pink4("pink4", 0x8b636c);
	framebuffer::basecolor palevioletred4("palevioletred4", 0x8b475d);
	framebuffer::basecolor palevioletred("palevioletred", 0xdb7093);
	framebuffer::basecolor palevioletred2("palevioletred2", 0xee799f);
	framebuffer::basecolor palevioletred1("palevioletred1", 0xff82ab);
	framebuffer::basecolor palevioletred3("palevioletred3", 0xcd6889);
	framebuffer::basecolor lavenderblush("lavenderblush", 0xfff0f5);
	framebuffer::basecolor lavenderblush1("lavenderblush1", 0xfff0f5);
	framebuffer::basecolor lavenderblush3("lavenderblush3", 0xcdc1c5);
	framebuffer::basecolor lavenderblush2("lavenderblush2", 0xeee0e5);
	framebuffer::basecolor lavenderblush4("lavenderblush4", 0x8b8386);
	framebuffer::basecolor maroon("maroon", 0xb03060);
	framebuffer::basecolor hotpink3("hotpink3", 0xcd6090);
	framebuffer::basecolor violetred3("violetred3", 0xcd3278);
	framebuffer::basecolor violetred1("violetred1", 0xff3e96);
	framebuffer::basecolor violetred2("violetred2", 0xee3a8c);
	framebuffer::basecolor violetred4("violetred4", 0x8b2252);
	framebuffer::basecolor hotpink2("hotpink2", 0xee6aa7);
	framebuffer::basecolor hotpink1("hotpink1", 0xff6eb4);
	framebuffer::basecolor hotpink4("hotpink4", 0x8b3a62);
	framebuffer::basecolor hotpink("hotpink", 0xff69b4);
	framebuffer::basecolor deeppink("deeppink", 0xff1493);
	framebuffer::basecolor deeppink1("deeppink1", 0xff1493);
	framebuffer::basecolor deeppink2("deeppink2", 0xee1289);
	framebuffer::basecolor deeppink3("deeppink3", 0xcd1076);
	framebuffer::basecolor deeppink4("deeppink4", 0x8b0a50);
	framebuffer::basecolor maroon1("maroon1", 0xff34b3);
	framebuffer::basecolor maroon2("maroon2", 0xee30a7);
	framebuffer::basecolor maroon3("maroon3", 0xcd2990);
	framebuffer::basecolor maroon4("maroon4", 0x8b1c62);
	framebuffer::basecolor mediumvioletred("mediumvioletred", 0xc71585);
	framebuffer::basecolor violetred("violetred", 0xd02090);
	framebuffer::basecolor orchid2("orchid2", 0xee7ae9);
	framebuffer::basecolor orchid("orchid", 0xda70d6);
	framebuffer::basecolor orchid1("orchid1", 0xff83fa);
	framebuffer::basecolor orchid3("orchid3", 0xcd69c9);
	framebuffer::basecolor orchid4("orchid4", 0x8b4789);
	framebuffer::basecolor thistle1("thistle1", 0xffe1ff);
	framebuffer::basecolor thistle2("thistle2", 0xeed2ee);
	framebuffer::basecolor plum1("plum1", 0xffbbff);
	framebuffer::basecolor plum2("plum2", 0xeeaeee);
	framebuffer::basecolor thistle("thistle", 0xd8bfd8);
	framebuffer::basecolor thistle3("thistle3", 0xcdb5cd);
	framebuffer::basecolor plum("plum", 0xdda0dd);
	framebuffer::basecolor violet("violet", 0xee82ee);
	framebuffer::basecolor plum3("plum3", 0xcd96cd);
	framebuffer::basecolor thistle4("thistle4", 0x8b7b8b);
	framebuffer::basecolor fuchsia("fuchsia", 0xff00ff);
	framebuffer::basecolor magenta("magenta", 0xff00ff);
	framebuffer::basecolor magenta1("magenta1", 0xff00ff);
	framebuffer::basecolor plum4("plum4", 0x8b668b);
	framebuffer::basecolor magenta2("magenta2", 0xee00ee);
	framebuffer::basecolor magenta3("magenta3", 0xcd00cd);
	framebuffer::basecolor darkmagenta("darkmagenta", 0x8b008b);
	framebuffer::basecolor magenta4("magenta4", 0x8b008b);
	framebuffer::basecolor mediumorchid("mediumorchid", 0xba55d3);
	framebuffer::basecolor mediumorchid1("mediumorchid1", 0xe066ff);
	framebuffer::basecolor mediumorchid2("mediumorchid2", 0xd15fee);
	framebuffer::basecolor mediumorchid3("mediumorchid3", 0xb452cd);
	framebuffer::basecolor mediumorchid4("mediumorchid4", 0x7a378b);
	framebuffer::basecolor darkviolet("darkviolet", 0x9400d3);
	framebuffer::basecolor darkorchid("darkorchid", 0x9932cc);
	framebuffer::basecolor darkorchid1("darkorchid1", 0xbf3eff);
	framebuffer::basecolor darkorchid3("darkorchid3", 0x9a32cd);
	framebuffer::basecolor darkorchid2("darkorchid2", 0xb23aee);
	framebuffer::basecolor darkorchid4("darkorchid4", 0x68228b);
	framebuffer::basecolor purple("purple", 0xa020f0);
	framebuffer::basecolor indigo("indigo", 0x4b0082);
	framebuffer::basecolor blueviolet("blueviolet", 0x8a2be2);
	framebuffer::basecolor purple2("purple2", 0x912cee);
	framebuffer::basecolor purple3("purple3", 0x7d26cd);
	framebuffer::basecolor purple4("purple4", 0x551a8b);
	framebuffer::basecolor purple1("purple1", 0x9b30ff);
	framebuffer::basecolor mediumpurple("mediumpurple", 0x9370db);
	framebuffer::basecolor mediumpurple1("mediumpurple1", 0xab82ff);
	framebuffer::basecolor mediumpurple2("mediumpurple2", 0x9f79ee);
	framebuffer::basecolor mediumpurple3("mediumpurple3", 0x8968cd);
	framebuffer::basecolor mediumpurple4("mediumpurple4", 0x5d478b);
	framebuffer::basecolor darkslateblue("darkslateblue", 0x483d8b);
	framebuffer::basecolor lightslateblue("lightslateblue", 0x8470ff);
	framebuffer::basecolor mediumslateblue("mediumslateblue", 0x7b68ee);
	framebuffer::basecolor slateblue("slateblue", 0x6a5acd);
	framebuffer::basecolor slateblue1("slateblue1", 0x836fff);
	framebuffer::basecolor slateblue2("slateblue2", 0x7a67ee);
	framebuffer::basecolor slateblue3("slateblue3", 0x6959cd);
	framebuffer::basecolor slateblue4("slateblue4", 0x473c8b);
	framebuffer::basecolor ghostwhite("ghostwhite", 0xf8f8ff);
	framebuffer::basecolor lavender("lavender", 0xe6e6fa);
	framebuffer::basecolor blue("blue", 0x0000ff);
	framebuffer::basecolor blue1("blue1", 0x0000ff);
	framebuffer::basecolor blue2("blue2", 0x0000ee);
	framebuffer::basecolor blue3("blue3", 0x0000cd);
	framebuffer::basecolor mediumblue("mediumblue", 0x0000cd);
	framebuffer::basecolor blue4("blue4", 0x00008b);
	framebuffer::basecolor darkblue("darkblue", 0x00008b);
	framebuffer::basecolor midnightblue("midnightblue", 0x191970);
	framebuffer::basecolor navy("navy", 0x000080);
	framebuffer::basecolor navyblue("navyblue", 0x000080);
	framebuffer::basecolor royalblue("royalblue", 0x4169e1);
	framebuffer::basecolor royalblue1("royalblue1", 0x4876ff);
	framebuffer::basecolor royalblue2("royalblue2", 0x436eee);
	framebuffer::basecolor royalblue3("royalblue3", 0x3a5fcd);
	framebuffer::basecolor royalblue4("royalblue4", 0x27408b);
	framebuffer::basecolor cornflowerblue("cornflowerblue", 0x6495ed);
	framebuffer::basecolor lightsteelblue("lightsteelblue", 0xb0c4de);
	framebuffer::basecolor lightsteelblue1("lightsteelblue1", 0xcae1ff);
	framebuffer::basecolor lightsteelblue2("lightsteelblue2", 0xbcd2ee);
	framebuffer::basecolor lightsteelblue3("lightsteelblue3", 0xa2b5cd);
	framebuffer::basecolor lightsteelblue4("lightsteelblue4", 0x6e7b8b);
	framebuffer::basecolor slategray4("slategray4", 0x6c7b8b);
	framebuffer::basecolor slategray1("slategray1", 0xc6e2ff);
	framebuffer::basecolor slategray2("slategray2", 0xb9d3ee);
	framebuffer::basecolor slategray3("slategray3", 0x9fb6cd);
	framebuffer::basecolor lightslategray("lightslategray", 0x778899);
	framebuffer::basecolor lightslategrey("lightslategrey", 0x778899);
	framebuffer::basecolor slategray("slategray", 0x708090);
	framebuffer::basecolor slategrey("slategrey", 0x708090);
	framebuffer::basecolor dodgerblue("dodgerblue", 0x1e90ff);
	framebuffer::basecolor dodgerblue1("dodgerblue1", 0x1e90ff);
	framebuffer::basecolor dodgerblue2("dodgerblue2", 0x1c86ee);
	framebuffer::basecolor dodgerblue4("dodgerblue4", 0x104e8b);
	framebuffer::basecolor dodgerblue3("dodgerblue3", 0x1874cd);
	framebuffer::basecolor aliceblue("aliceblue", 0xf0f8ff);
	framebuffer::basecolor steelblue4("steelblue4", 0x36648b);
	framebuffer::basecolor steelblue("steelblue", 0x4682b4);
	framebuffer::basecolor steelblue1("steelblue1", 0x63b8ff);
	framebuffer::basecolor steelblue2("steelblue2", 0x5cacee);
	framebuffer::basecolor steelblue3("steelblue3", 0x4f94cd);
	framebuffer::basecolor skyblue4("skyblue4", 0x4a708b);
	framebuffer::basecolor skyblue1("skyblue1", 0x87ceff);
	framebuffer::basecolor skyblue2("skyblue2", 0x7ec0ee);
	framebuffer::basecolor skyblue3("skyblue3", 0x6ca6cd);
	framebuffer::basecolor lightskyblue("lightskyblue", 0x87cefa);
	framebuffer::basecolor lightskyblue4("lightskyblue4", 0x607b8b);
	framebuffer::basecolor lightskyblue1("lightskyblue1", 0xb0e2ff);
	framebuffer::basecolor lightskyblue2("lightskyblue2", 0xa4d3ee);
	framebuffer::basecolor lightskyblue3("lightskyblue3", 0x8db6cd);
	framebuffer::basecolor skyblue("skyblue", 0x87ceeb);
	framebuffer::basecolor lightblue3("lightblue3", 0x9ac0cd);
	framebuffer::basecolor deepskyblue("deepskyblue", 0x00bfff);
	framebuffer::basecolor deepskyblue1("deepskyblue1", 0x00bfff);
	framebuffer::basecolor deepskyblue2("deepskyblue2", 0x00b2ee);
	framebuffer::basecolor deepskyblue4("deepskyblue4", 0x00688b);
	framebuffer::basecolor deepskyblue3("deepskyblue3", 0x009acd);
	framebuffer::basecolor lightblue1("lightblue1", 0xbfefff);
	framebuffer::basecolor lightblue2("lightblue2", 0xb2dfee);
	framebuffer::basecolor lightblue("lightblue", 0xadd8e6);
	framebuffer::basecolor lightblue4("lightblue4", 0x68838b);
	framebuffer::basecolor powderblue("powderblue", 0xb0e0e6);
	framebuffer::basecolor cadetblue1("cadetblue1", 0x98f5ff);
	framebuffer::basecolor cadetblue2("cadetblue2", 0x8ee5ee);
	framebuffer::basecolor cadetblue3("cadetblue3", 0x7ac5cd);
	framebuffer::basecolor cadetblue4("cadetblue4", 0x53868b);
	framebuffer::basecolor turquoise1("turquoise1", 0x00f5ff);
	framebuffer::basecolor turquoise2("turquoise2", 0x00e5ee);
	framebuffer::basecolor turquoise3("turquoise3", 0x00c5cd);
	framebuffer::basecolor turquoise4("turquoise4", 0x00868b);
	framebuffer::basecolor cadet("cadet", 0x5f9ea0);
	framebuffer::basecolor cadetblue("cadetblue", 0x5f9ea0);
	framebuffer::basecolor darkturquoise("darkturquoise", 0x00ced1);
	framebuffer::basecolor azure("azure", 0xf0ffff);
	framebuffer::basecolor azure1("azure1", 0xf0ffff);
	framebuffer::basecolor lightcyan("lightcyan", 0xe0ffff);
	framebuffer::basecolor lightcyan1("lightcyan1", 0xe0ffff);
	framebuffer::basecolor azure2("azure2", 0xe0eeee);
	framebuffer::basecolor lightcyan2("lightcyan2", 0xd1eeee);
	framebuffer::basecolor paleturquoise1("paleturquoise1", 0xbbffff);
	framebuffer::basecolor paleturquoise("paleturquoise", 0xafeeee);
	framebuffer::basecolor paleturquoise2("paleturquoise2", 0xaeeeee);
	framebuffer::basecolor darkslategray1("darkslategray1", 0x97ffff);
	framebuffer::basecolor azure3("azure3", 0xc1cdcd);
	framebuffer::basecolor lightcyan3("lightcyan3", 0xb4cdcd);
	framebuffer::basecolor darkslategray2("darkslategray2", 0x8deeee);
	framebuffer::basecolor paleturquoise3("paleturquoise3", 0x96cdcd);
	framebuffer::basecolor darkslategray3("darkslategray3", 0x79cdcd);
	framebuffer::basecolor azure4("azure4", 0x838b8b);
	framebuffer::basecolor lightcyan4("lightcyan4", 0x7a8b8b);
	framebuffer::basecolor aqua("aqua", 0x00ffff);
	framebuffer::basecolor cyan("cyan", 0x00ffff);
	framebuffer::basecolor cyan1("cyan1", 0x00ffff);
	framebuffer::basecolor paleturquoise4("paleturquoise4", 0x668b8b);
	framebuffer::basecolor cyan2("cyan2", 0x00eeee);
	framebuffer::basecolor darkslategray4("darkslategray4", 0x528b8b);
	framebuffer::basecolor cyan3("cyan3", 0x00cdcd);
	framebuffer::basecolor cyan4("cyan4", 0x008b8b);
	framebuffer::basecolor darkcyan("darkcyan", 0x008b8b);
	framebuffer::basecolor teal("teal", 0x008080);
	framebuffer::basecolor darkslategray("darkslategray", 0x2f4f4f);
	framebuffer::basecolor darkslategrey("darkslategrey", 0x2f4f4f);
	framebuffer::basecolor mediumturquoise("mediumturquoise", 0x48d1cc);
	framebuffer::basecolor lightseagreen("lightseagreen", 0x20b2aa);
	framebuffer::basecolor turquoise("turquoise", 0x40e0d0);
	framebuffer::basecolor aquamarine4("aquamarine4", 0x458b74);
	framebuffer::basecolor aquamarine("aquamarine", 0x7fffd4);
	framebuffer::basecolor aquamarine1("aquamarine1", 0x7fffd4);
	framebuffer::basecolor aquamarine2("aquamarine2", 0x76eec6);
	framebuffer::basecolor aquamarine3("aquamarine3", 0x66cdaa);
	framebuffer::basecolor mediumaquamarine("mediumaquamarine", 0x66cdaa);
	framebuffer::basecolor mediumspringgreen("mediumspringgreen", 0x00fa9a);
	framebuffer::basecolor mintcream("mintcream", 0xf5fffa);
	framebuffer::basecolor springgreen("springgreen", 0x00ff7f);
	framebuffer::basecolor springgreen1("springgreen1", 0x00ff7f);
	framebuffer::basecolor springgreen2("springgreen2", 0x00ee76);
	framebuffer::basecolor springgreen3("springgreen3", 0x00cd66);
	framebuffer::basecolor springgreen4("springgreen4", 0x008b45);
	framebuffer::basecolor mediumseagreen("mediumseagreen", 0x3cb371);
	framebuffer::basecolor seagreen("seagreen", 0x2e8b57);
	framebuffer::basecolor seagreen3("seagreen3", 0x43cd80);
	framebuffer::basecolor seagreen1("seagreen1", 0x54ff9f);
	framebuffer::basecolor seagreen4("seagreen4", 0x2e8b57);
	framebuffer::basecolor seagreen2("seagreen2", 0x4eee94);
	framebuffer::basecolor mediumforestgreen("mediumforestgreen", 0x32814b);
	framebuffer::basecolor honeydew("honeydew", 0xf0fff0);
	framebuffer::basecolor honeydew1("honeydew1", 0xf0fff0);
	framebuffer::basecolor honeydew2("honeydew2", 0xe0eee0);
	framebuffer::basecolor darkseagreen1("darkseagreen1", 0xc1ffc1);
	framebuffer::basecolor darkseagreen2("darkseagreen2", 0xb4eeb4);
	framebuffer::basecolor palegreen1("palegreen1", 0x9aff9a);
	framebuffer::basecolor palegreen("palegreen", 0x98fb98);
	framebuffer::basecolor honeydew3("honeydew3", 0xc1cdc1);
	framebuffer::basecolor lightgreen("lightgreen", 0x90ee90);
	framebuffer::basecolor palegreen2("palegreen2", 0x90ee90);
	framebuffer::basecolor darkseagreen3("darkseagreen3", 0x9bcd9b);
	framebuffer::basecolor darkseagreen("darkseagreen", 0x8fbc8f);
	framebuffer::basecolor palegreen3("palegreen3", 0x7ccd7c);
	framebuffer::basecolor honeydew4("honeydew4", 0x838b83);
	framebuffer::basecolor green1("green1", 0x00ff00);
	framebuffer::basecolor lime("lime", 0x00ff00);
	framebuffer::basecolor limegreen("limegreen", 0x32cd32);
	framebuffer::basecolor darkseagreen4("darkseagreen4", 0x698b69);
	framebuffer::basecolor green2("green2", 0x00ee00);
	framebuffer::basecolor palegreen4("palegreen4", 0x548b54);
	framebuffer::basecolor green3("green3", 0x00cd00);
	framebuffer::basecolor forestgreen("forestgreen", 0x228b22);
	framebuffer::basecolor green4("green4", 0x008b00);
	framebuffer::basecolor green("green", 0x008000);
	framebuffer::basecolor darkgreen("darkgreen", 0x006400);
	framebuffer::basecolor lawngreen("lawngreen", 0x7cfc00);
	framebuffer::basecolor chartreuse("chartreuse", 0x7fff00);
	framebuffer::basecolor chartreuse1("chartreuse1", 0x7fff00);
	framebuffer::basecolor chartreuse2("chartreuse2", 0x76ee00);
	framebuffer::basecolor chartreuse3("chartreuse3", 0x66cd00);
	framebuffer::basecolor chartreuse4("chartreuse4", 0x458b00);
	framebuffer::basecolor greenyellow("greenyellow", 0xadff2f);
	framebuffer::basecolor darkolivegreen3("darkolivegreen3", 0xa2cd5a);
	framebuffer::basecolor darkolivegreen1("darkolivegreen1", 0xcaff70);
	framebuffer::basecolor darkolivegreen2("darkolivegreen2", 0xbcee68);
	framebuffer::basecolor darkolivegreen4("darkolivegreen4", 0x6e8b3d);
	framebuffer::basecolor darkolivegreen("darkolivegreen", 0x556b2f);
	framebuffer::basecolor olivedrab("olivedrab", 0x6b8e23);
	framebuffer::basecolor olivedrab1("olivedrab1", 0xc0ff3e);
	framebuffer::basecolor olivedrab2("olivedrab2", 0xb3ee3a);
	framebuffer::basecolor olivedrab3("olivedrab3", 0x9acd32);
	framebuffer::basecolor yellowgreen("yellowgreen", 0x9acd32);
	framebuffer::basecolor olivedrab4("olivedrab4", 0x698b22);
	framebuffer::basecolor ivory("ivory", 0xfffff0);
	framebuffer::basecolor ivory1("ivory1", 0xfffff0);
	framebuffer::basecolor lightyellow("lightyellow", 0xffffe0);
	framebuffer::basecolor lightyellow1("lightyellow1", 0xffffe0);
	framebuffer::basecolor beige("beige", 0xf5f5dc);
	framebuffer::basecolor ivory2("ivory2", 0xeeeee0);
	framebuffer::basecolor lightgoldenrodyellow("lightgoldenrodyellow", 0xfafad2);
	framebuffer::basecolor lightyellow2("lightyellow2", 0xeeeed1);
	framebuffer::basecolor ivory3("ivory3", 0xcdcdc1);
	framebuffer::basecolor lightyellow3("lightyellow3", 0xcdcdb4);
	framebuffer::basecolor ivory4("ivory4", 0x8b8b83);
	framebuffer::basecolor lightyellow4("lightyellow4", 0x8b8b7a);
	framebuffer::basecolor yellow("yellow", 0xffff00);
	framebuffer::basecolor yellow1("yellow1", 0xffff00);
	framebuffer::basecolor yellow2("yellow2", 0xeeee00);
	framebuffer::basecolor yellow3("yellow3", 0xcdcd00);
	framebuffer::basecolor yellow4("yellow4", 0x8b8b00);
	framebuffer::basecolor olive("olive", 0x808000);
	framebuffer::basecolor darkkhaki("darkkhaki", 0xbdb76b);
	framebuffer::basecolor khaki2("khaki2", 0xeee685);
	framebuffer::basecolor lemonchiffon4("lemonchiffon4", 0x8b8970);
	framebuffer::basecolor khaki1("khaki1", 0xfff68f);
	framebuffer::basecolor khaki3("khaki3", 0xcdc673);
	framebuffer::basecolor khaki4("khaki4", 0x8b864e);
	framebuffer::basecolor palegoldenrod("palegoldenrod", 0xeee8aa);
	framebuffer::basecolor lemonchiffon("lemonchiffon", 0xfffacd);
	framebuffer::basecolor lemonchiffon1("lemonchiffon1", 0xfffacd);
	framebuffer::basecolor khaki("khaki", 0xf0e68c);
	framebuffer::basecolor lemonchiffon3("lemonchiffon3", 0xcdc9a5);
	framebuffer::basecolor lemonchiffon2("lemonchiffon2", 0xeee9bf);
	framebuffer::basecolor mediumgoldenrod("mediumgoldenrod", 0xd1c166);
	framebuffer::basecolor cornsilk4("cornsilk4", 0x8b8878);
	framebuffer::basecolor gold("gold", 0xffd700);
	framebuffer::basecolor gold1("gold1", 0xffd700);
	framebuffer::basecolor gold2("gold2", 0xeec900);
	framebuffer::basecolor gold3("gold3", 0xcdad00);
	framebuffer::basecolor gold4("gold4", 0x8b7500);
	framebuffer::basecolor lightgoldenrod("lightgoldenrod", 0xeedd82);
	framebuffer::basecolor lightgoldenrod4("lightgoldenrod4", 0x8b814c);
	framebuffer::basecolor lightgoldenrod1("lightgoldenrod1", 0xffec8b);
	framebuffer::basecolor lightgoldenrod3("lightgoldenrod3", 0xcdbe70);
	framebuffer::basecolor lightgoldenrod2("lightgoldenrod2", 0xeedc82);
	framebuffer::basecolor cornsilk3("cornsilk3", 0xcdc8b1);
	framebuffer::basecolor cornsilk2("cornsilk2", 0xeee8cd);
	framebuffer::basecolor cornsilk("cornsilk", 0xfff8dc);
	framebuffer::basecolor cornsilk1("cornsilk1", 0xfff8dc);
	framebuffer::basecolor goldenrod("goldenrod", 0xdaa520);
	framebuffer::basecolor goldenrod1("goldenrod1", 0xffc125);
	framebuffer::basecolor goldenrod2("goldenrod2", 0xeeb422);
	framebuffer::basecolor goldenrod3("goldenrod3", 0xcd9b1d);
	framebuffer::basecolor goldenrod4("goldenrod4", 0x8b6914);
	framebuffer::basecolor darkgoldenrod("darkgoldenrod", 0xb8860b);
	framebuffer::basecolor darkgoldenrod1("darkgoldenrod1", 0xffb90f);
	framebuffer::basecolor darkgoldenrod2("darkgoldenrod2", 0xeead0e);
	framebuffer::basecolor darkgoldenrod3("darkgoldenrod3", 0xcd950c);
	framebuffer::basecolor darkgoldenrod4("darkgoldenrod4", 0x8b6508);
	framebuffer::basecolor floralwhite("floralwhite", 0xfffaf0);
	framebuffer::basecolor wheat2("wheat2", 0xeed8ae);
	framebuffer::basecolor oldlace("oldlace", 0xfdf5e6);
	framebuffer::basecolor wheat("wheat", 0xf5deb3);
	framebuffer::basecolor wheat1("wheat1", 0xffe7ba);
	framebuffer::basecolor wheat3("wheat3", 0xcdba96);
	framebuffer::basecolor orange("orange", 0xffa500);
	framebuffer::basecolor orange1("orange1", 0xffa500);
	framebuffer::basecolor orange2("orange2", 0xee9a00);
	framebuffer::basecolor orange3("orange3", 0xcd8500);
	framebuffer::basecolor orange4("orange4", 0x8b5a00);
	framebuffer::basecolor wheat4("wheat4", 0x8b7e66);
	framebuffer::basecolor moccasin("moccasin", 0xffe4b5);
	framebuffer::basecolor papayawhip("papayawhip", 0xffefd5);
	framebuffer::basecolor navajowhite3("navajowhite3", 0xcdb38b);
	framebuffer::basecolor blanchedalmond("blanchedalmond", 0xffebcd);
	framebuffer::basecolor navajowhite("navajowhite", 0xffdead);
	framebuffer::basecolor navajowhite1("navajowhite1", 0xffdead);
	framebuffer::basecolor navajowhite2("navajowhite2", 0xeecfa1);
	framebuffer::basecolor navajowhite4("navajowhite4", 0x8b795e);
	framebuffer::basecolor antiquewhite4("antiquewhite4", 0x8b8378);
	framebuffer::basecolor antiquewhite("antiquewhite", 0xfaebd7);
	framebuffer::basecolor tan("tan", 0xd2b48c);
	framebuffer::basecolor bisque4("bisque4", 0x8b7d6b);
	framebuffer::basecolor burlywood("burlywood", 0xdeb887);
	framebuffer::basecolor antiquewhite2("antiquewhite2", 0xeedfcc);
	framebuffer::basecolor burlywood1("burlywood1", 0xffd39b);
	framebuffer::basecolor burlywood3("burlywood3", 0xcdaa7d);
	framebuffer::basecolor burlywood2("burlywood2", 0xeec591);
	framebuffer::basecolor antiquewhite1("antiquewhite1", 0xffefdb);
	framebuffer::basecolor burlywood4("burlywood4", 0x8b7355);
	framebuffer::basecolor antiquewhite3("antiquewhite3", 0xcdc0b0);
	framebuffer::basecolor darkorange("darkorange", 0xff8c00);
	framebuffer::basecolor bisque2("bisque2", 0xeed5b7);
	framebuffer::basecolor bisque("bisque", 0xffe4c4);
	framebuffer::basecolor bisque1("bisque1", 0xffe4c4);
	framebuffer::basecolor bisque3("bisque3", 0xcdb79e);
	framebuffer::basecolor darkorange1("darkorange1", 0xff7f00);
	framebuffer::basecolor linen("linen", 0xfaf0e6);
	framebuffer::basecolor darkorange2("darkorange2", 0xee7600);
	framebuffer::basecolor darkorange3("darkorange3", 0xcd6600);
	framebuffer::basecolor darkorange4("darkorange4", 0x8b4500);
	framebuffer::basecolor peru("peru", 0xcd853f);
	framebuffer::basecolor tan1("tan1", 0xffa54f);
	framebuffer::basecolor tan2("tan2", 0xee9a49);
	framebuffer::basecolor tan3("tan3", 0xcd853f);
	framebuffer::basecolor tan4("tan4", 0x8b5a2b);
	framebuffer::basecolor peachpuff("peachpuff", 0xffdab9);
	framebuffer::basecolor peachpuff1("peachpuff1", 0xffdab9);
	framebuffer::basecolor peachpuff4("peachpuff4", 0x8b7765);
	framebuffer::basecolor peachpuff2("peachpuff2", 0xeecbad);
	framebuffer::basecolor peachpuff3("peachpuff3", 0xcdaf95);
	framebuffer::basecolor sandybrown("sandybrown", 0xf4a460);
	framebuffer::basecolor seashell4("seashell4", 0x8b8682);
	framebuffer::basecolor seashell2("seashell2", 0xeee5de);
	framebuffer::basecolor seashell3("seashell3", 0xcdc5bf);
	framebuffer::basecolor chocolate("chocolate", 0xd2691e);
	framebuffer::basecolor chocolate1("chocolate1", 0xff7f24);
	framebuffer::basecolor chocolate2("chocolate2", 0xee7621);
	framebuffer::basecolor chocolate3("chocolate3", 0xcd661d);
	framebuffer::basecolor chocolate4("chocolate4", 0x8b4513);
	framebuffer::basecolor saddlebrown("saddlebrown", 0x8b4513);
	framebuffer::basecolor seashell("seashell", 0xfff5ee);
	framebuffer::basecolor seashell1("seashell1", 0xfff5ee);
	framebuffer::basecolor sienna4("sienna4", 0x8b4726);
	framebuffer::basecolor sienna("sienna", 0xa0522d);
	framebuffer::basecolor sienna1("sienna1", 0xff8247);
	framebuffer::basecolor sienna2("sienna2", 0xee7942);
	framebuffer::basecolor sienna3("sienna3", 0xcd6839);
	framebuffer::basecolor lightsalmon3("lightsalmon3", 0xcd8162);
	framebuffer::basecolor lightsalmon("lightsalmon", 0xffa07a);
	framebuffer::basecolor lightsalmon1("lightsalmon1", 0xffa07a);
	framebuffer::basecolor lightsalmon4("lightsalmon4", 0x8b5742);
	framebuffer::basecolor lightsalmon2("lightsalmon2", 0xee9572);
	framebuffer::basecolor coral("coral", 0xff7f50);
	framebuffer::basecolor orangered("orangered", 0xff4500);
	framebuffer::basecolor orangered1("orangered1", 0xff4500);
	framebuffer::basecolor orangered2("orangered2", 0xee4000);
	framebuffer::basecolor orangered3("orangered3", 0xcd3700);
	framebuffer::basecolor orangered4("orangered4", 0x8b2500);
	framebuffer::basecolor darksalmon("darksalmon", 0xe9967a);
	framebuffer::basecolor salmon1("salmon1", 0xff8c69);
	framebuffer::basecolor salmon2("salmon2", 0xee8262);
	framebuffer::basecolor salmon3("salmon3", 0xcd7054);
	framebuffer::basecolor salmon4("salmon4", 0x8b4c39);
	framebuffer::basecolor coral1("coral1", 0xff7256);
	framebuffer::basecolor coral2("coral2", 0xee6a50);
	framebuffer::basecolor coral3("coral3", 0xcd5b45);
	framebuffer::basecolor coral4("coral4", 0x8b3e2f);
	framebuffer::basecolor tomato4("tomato4", 0x8b3626);
	framebuffer::basecolor tomato("tomato", 0xff6347);
	framebuffer::basecolor tomato1("tomato1", 0xff6347);
	framebuffer::basecolor tomato2("tomato2", 0xee5c42);
	framebuffer::basecolor tomato3("tomato3", 0xcd4f39);
	framebuffer::basecolor mistyrose4("mistyrose4", 0x8b7d7b);
	framebuffer::basecolor mistyrose2("mistyrose2", 0xeed5d2);
	framebuffer::basecolor mistyrose("mistyrose", 0xffe4e1);
	framebuffer::basecolor mistyrose1("mistyrose1", 0xffe4e1);
	framebuffer::basecolor salmon("salmon", 0xfa8072);
	framebuffer::basecolor mistyrose3("mistyrose3", 0xcdb7b5);
	framebuffer::basecolor white("white", 0xffffff);
	framebuffer::basecolor gray100("gray100", 0xffffff);
	framebuffer::basecolor grey100("grey100", 0xffffff);
	framebuffer::basecolor gray99("gray99", 0xfcfcfc);
	framebuffer::basecolor grey99("grey99", 0xfcfcfc);
	framebuffer::basecolor gray98("gray98", 0xfafafa);
	framebuffer::basecolor grey98("grey98", 0xfafafa);
	framebuffer::basecolor gray97("gray97", 0xf7f7f7);
	framebuffer::basecolor grey97("grey97", 0xf7f7f7);
	framebuffer::basecolor gray96("gray96", 0xf5f5f5);
	framebuffer::basecolor grey96("grey96", 0xf5f5f5);
	framebuffer::basecolor whitesmoke("whitesmoke", 0xf5f5f5);
	framebuffer::basecolor gray95("gray95", 0xf2f2f2);
	framebuffer::basecolor grey95("grey95", 0xf2f2f2);
	framebuffer::basecolor gray94("gray94", 0xf0f0f0);
	framebuffer::basecolor grey94("grey94", 0xf0f0f0);
	framebuffer::basecolor gray93("gray93", 0xededed);
	framebuffer::basecolor grey93("grey93", 0xededed);
	framebuffer::basecolor gray92("gray92", 0xebebeb);
	framebuffer::basecolor grey92("grey92", 0xebebeb);
	framebuffer::basecolor gray91("gray91", 0xe8e8e8);
	framebuffer::basecolor grey91("grey91", 0xe8e8e8);
	framebuffer::basecolor gray90("gray90", 0xe5e5e5);
	framebuffer::basecolor grey90("grey90", 0xe5e5e5);
	framebuffer::basecolor gray89("gray89", 0xe3e3e3);
	framebuffer::basecolor grey89("grey89", 0xe3e3e3);
	framebuffer::basecolor gray88("gray88", 0xe0e0e0);
	framebuffer::basecolor grey88("grey88", 0xe0e0e0);
	framebuffer::basecolor gray87("gray87", 0xdedede);
	framebuffer::basecolor grey87("grey87", 0xdedede);
	framebuffer::basecolor gainsboro("gainsboro", 0xdcdcdc);
	framebuffer::basecolor gray86("gray86", 0xdbdbdb);
	framebuffer::basecolor grey86("grey86", 0xdbdbdb);
	framebuffer::basecolor gray85("gray85", 0xd9d9d9);
	framebuffer::basecolor grey85("grey85", 0xd9d9d9);
	framebuffer::basecolor gray84("gray84", 0xd6d6d6);
	framebuffer::basecolor grey84("grey84", 0xd6d6d6);
	framebuffer::basecolor gray83("gray83", 0xd4d4d4);
	framebuffer::basecolor grey83("grey83", 0xd4d4d4);
	framebuffer::basecolor lightgray("lightgray", 0xd3d3d3);
	framebuffer::basecolor lightgrey("lightgrey", 0xd3d3d3);
	framebuffer::basecolor gray82("gray82", 0xd1d1d1);
	framebuffer::basecolor grey82("grey82", 0xd1d1d1);
	framebuffer::basecolor gray81("gray81", 0xcfcfcf);
	framebuffer::basecolor grey81("grey81", 0xcfcfcf);
	framebuffer::basecolor gray80("gray80", 0xcccccc);
	framebuffer::basecolor grey80("grey80", 0xcccccc);
	framebuffer::basecolor gray79("gray79", 0xc9c9c9);
	framebuffer::basecolor grey79("grey79", 0xc9c9c9);
	framebuffer::basecolor gray78("gray78", 0xc7c7c7);
	framebuffer::basecolor grey78("grey78", 0xc7c7c7);
	framebuffer::basecolor gray77("gray77", 0xc4c4c4);
	framebuffer::basecolor grey77("grey77", 0xc4c4c4);
	framebuffer::basecolor gray76("gray76", 0xc2c2c2);
	framebuffer::basecolor grey76("grey76", 0xc2c2c2);
	framebuffer::basecolor silver("silver", 0xc0c0c0);
	framebuffer::basecolor gray75("gray75", 0xbfbfbf);
	framebuffer::basecolor grey75("grey75", 0xbfbfbf);
	framebuffer::basecolor gray74("gray74", 0xbdbdbd);
	framebuffer::basecolor grey74("grey74", 0xbdbdbd);
	framebuffer::basecolor gray73("gray73", 0xbababa);
	framebuffer::basecolor grey73("grey73", 0xbababa);
	framebuffer::basecolor gray72("gray72", 0xb8b8b8);
	framebuffer::basecolor grey72("grey72", 0xb8b8b8);
	framebuffer::basecolor gray71("gray71", 0xb5b5b5);
	framebuffer::basecolor grey71("grey71", 0xb5b5b5);
	framebuffer::basecolor gray70("gray70", 0xb3b3b3);
	framebuffer::basecolor grey70("grey70", 0xb3b3b3);
	framebuffer::basecolor gray69("gray69", 0xb0b0b0);
	framebuffer::basecolor grey69("grey69", 0xb0b0b0);
	framebuffer::basecolor gray68("gray68", 0xadadad);
	framebuffer::basecolor grey68("grey68", 0xadadad);
	framebuffer::basecolor gray67("gray67", 0xababab);
	framebuffer::basecolor grey67("grey67", 0xababab);
	framebuffer::basecolor darkgray("darkgray", 0xa9a9a9);
	framebuffer::basecolor darkgrey("darkgrey", 0xa9a9a9);
	framebuffer::basecolor gray66("gray66", 0xa8a8a8);
	framebuffer::basecolor grey66("grey66", 0xa8a8a8);
	framebuffer::basecolor gray65("gray65", 0xa6a6a6);
	framebuffer::basecolor grey65("grey65", 0xa6a6a6);
	framebuffer::basecolor gray64("gray64", 0xa3a3a3);
	framebuffer::basecolor grey64("grey64", 0xa3a3a3);
	framebuffer::basecolor gray63("gray63", 0xa1a1a1);
	framebuffer::basecolor grey63("grey63", 0xa1a1a1);
	framebuffer::basecolor gray62("gray62", 0x9e9e9e);
	framebuffer::basecolor grey62("grey62", 0x9e9e9e);
	framebuffer::basecolor gray61("gray61", 0x9c9c9c);
	framebuffer::basecolor grey61("grey61", 0x9c9c9c);
	framebuffer::basecolor gray60("gray60", 0x999999);
	framebuffer::basecolor grey60("grey60", 0x999999);
	framebuffer::basecolor gray59("gray59", 0x969696);
	framebuffer::basecolor grey59("grey59", 0x969696);
	framebuffer::basecolor gray58("gray58", 0x949494);
	framebuffer::basecolor grey58("grey58", 0x949494);
	framebuffer::basecolor gray57("gray57", 0x919191);
	framebuffer::basecolor grey57("grey57", 0x919191);
	framebuffer::basecolor gray56("gray56", 0x8f8f8f);
	framebuffer::basecolor grey56("grey56", 0x8f8f8f);
	framebuffer::basecolor gray55("gray55", 0x8c8c8c);
	framebuffer::basecolor grey55("grey55", 0x8c8c8c);
	framebuffer::basecolor gray54("gray54", 0x8a8a8a);
	framebuffer::basecolor grey54("grey54", 0x8a8a8a);
	framebuffer::basecolor gray53("gray53", 0x878787);
	framebuffer::basecolor grey53("grey53", 0x878787);
	framebuffer::basecolor gray52("gray52", 0x858585);
	framebuffer::basecolor grey52("grey52", 0x858585);
	framebuffer::basecolor gray51("gray51", 0x828282);
	framebuffer::basecolor grey51("grey51", 0x828282);
	framebuffer::basecolor fractal("fractal", 0x808080);
	framebuffer::basecolor gray50("gray50", 0x7f7f7f);
	framebuffer::basecolor grey50("grey50", 0x7f7f7f);
	framebuffer::basecolor gray("gray", 0x7e7e7e);
	framebuffer::basecolor gray49("gray49", 0x7d7d7d);
	framebuffer::basecolor grey49("grey49", 0x7d7d7d);
	framebuffer::basecolor gray48("gray48", 0x7a7a7a);
	framebuffer::basecolor grey48("grey48", 0x7a7a7a);
	framebuffer::basecolor gray47("gray47", 0x787878);
	framebuffer::basecolor grey47("grey47", 0x787878);
	framebuffer::basecolor gray46("gray46", 0x757575);
	framebuffer::basecolor grey46("grey46", 0x757575);
	framebuffer::basecolor gray45("gray45", 0x737373);
	framebuffer::basecolor grey45("grey45", 0x737373);
	framebuffer::basecolor gray44("gray44", 0x707070);
	framebuffer::basecolor grey44("grey44", 0x707070);
	framebuffer::basecolor gray43("gray43", 0x6e6e6e);
	framebuffer::basecolor grey43("grey43", 0x6e6e6e);
	framebuffer::basecolor gray42("gray42", 0x6b6b6b);
	framebuffer::basecolor grey42("grey42", 0x6b6b6b);
	framebuffer::basecolor dimgray("dimgray", 0x696969);
	framebuffer::basecolor dimgrey("dimgrey", 0x696969);
	framebuffer::basecolor gray41("gray41", 0x696969);
	framebuffer::basecolor grey41("grey41", 0x696969);
	framebuffer::basecolor gray40("gray40", 0x666666);
	framebuffer::basecolor grey40("grey40", 0x666666);
	framebuffer::basecolor gray39("gray39", 0x636363);
	framebuffer::basecolor grey39("grey39", 0x636363);
	framebuffer::basecolor gray38("gray38", 0x616161);
	framebuffer::basecolor grey38("grey38", 0x616161);
	framebuffer::basecolor gray37("gray37", 0x5e5e5e);
	framebuffer::basecolor grey37("grey37", 0x5e5e5e);
	framebuffer::basecolor gray36("gray36", 0x5c5c5c);
	framebuffer::basecolor grey36("grey36", 0x5c5c5c);
	framebuffer::basecolor gray35("gray35", 0x595959);
	framebuffer::basecolor grey35("grey35", 0x595959);
	framebuffer::basecolor gray34("gray34", 0x575757);
	framebuffer::basecolor grey34("grey34", 0x575757);
	framebuffer::basecolor gray33("gray33", 0x545454);
	framebuffer::basecolor grey33("grey33", 0x545454);
	framebuffer::basecolor gray32("gray32", 0x525252);
	framebuffer::basecolor grey32("grey32", 0x525252);
	framebuffer::basecolor gray31("gray31", 0x4f4f4f);
	framebuffer::basecolor grey31("grey31", 0x4f4f4f);
	framebuffer::basecolor gray30("gray30", 0x4d4d4d);
	framebuffer::basecolor grey30("grey30", 0x4d4d4d);
	framebuffer::basecolor gray29("gray29", 0x4a4a4a);
	framebuffer::basecolor grey29("grey29", 0x4a4a4a);
	framebuffer::basecolor gray28("gray28", 0x474747);
	framebuffer::basecolor grey28("grey28", 0x474747);
	framebuffer::basecolor gray27("gray27", 0x454545);
	framebuffer::basecolor grey27("grey27", 0x454545);
	framebuffer::basecolor gray26("gray26", 0x424242);
	framebuffer::basecolor grey26("grey26", 0x424242);
	framebuffer::basecolor gray25("gray25", 0x404040);
	framebuffer::basecolor grey25("grey25", 0x404040);
	framebuffer::basecolor gray24("gray24", 0x3d3d3d);
	framebuffer::basecolor grey24("grey24", 0x3d3d3d);
	framebuffer::basecolor gray23("gray23", 0x3b3b3b);
	framebuffer::basecolor grey23("grey23", 0x3b3b3b);
	framebuffer::basecolor gray22("gray22", 0x383838);
	framebuffer::basecolor grey22("grey22", 0x383838);
	framebuffer::basecolor gray21("gray21", 0x363636);
	framebuffer::basecolor grey21("grey21", 0x363636);
	framebuffer::basecolor gray20("gray20", 0x333333);
	framebuffer::basecolor grey20("grey20", 0x333333);
	framebuffer::basecolor gray19("gray19", 0x303030);
	framebuffer::basecolor grey19("grey19", 0x303030);
	framebuffer::basecolor gray18("gray18", 0x2e2e2e);
	framebuffer::basecolor grey18("grey18", 0x2e2e2e);
	framebuffer::basecolor gray17("gray17", 0x2b2b2b);
	framebuffer::basecolor grey17("grey17", 0x2b2b2b);
	framebuffer::basecolor gray16("gray16", 0x292929);
	framebuffer::basecolor grey16("grey16", 0x292929);
	framebuffer::basecolor gray15("gray15", 0x262626);
	framebuffer::basecolor grey15("grey15", 0x262626);
	framebuffer::basecolor gray14("gray14", 0x242424);
	framebuffer::basecolor grey14("grey14", 0x242424);
	framebuffer::basecolor gray13("gray13", 0x212121);
	framebuffer::basecolor grey13("grey13", 0x212121);
	framebuffer::basecolor gray12("gray12", 0x1f1f1f);
	framebuffer::basecolor grey12("grey12", 0x1f1f1f);
	framebuffer::basecolor gray11("gray11", 0x1c1c1c);
	framebuffer::basecolor grey11("grey11", 0x1c1c1c);
	framebuffer::basecolor gray10("gray10", 0x1a1a1a);
	framebuffer::basecolor grey10("grey10", 0x1a1a1a);
	framebuffer::basecolor gray9("gray9", 0x171717);
	framebuffer::basecolor grey9("grey9", 0x171717);
	framebuffer::basecolor gray8("gray8", 0x141414);
	framebuffer::basecolor grey8("grey8", 0x141414);
	framebuffer::basecolor gray7("gray7", 0x121212);
	framebuffer::basecolor grey7("grey7", 0x121212);
	framebuffer::basecolor gray6("gray6", 0x0f0f0f);
	framebuffer::basecolor grey6("grey6", 0x0f0f0f);
	framebuffer::basecolor gray5("gray5", 0x0d0d0d);
	framebuffer::basecolor grey5("grey5", 0x0d0d0d);
	framebuffer::basecolor gray4("gray4", 0x0a0a0a);
	framebuffer::basecolor grey4("grey4", 0x0a0a0a);
	framebuffer::basecolor gray3("gray3", 0x080808);
	framebuffer::basecolor grey3("grey3", 0x080808);
	framebuffer::basecolor gray2("gray2", 0x050505);
	framebuffer::basecolor grey2("grey2", 0x050505);
	framebuffer::basecolor gray1("gray1", 0x030303);
	framebuffer::basecolor grey1("grey1", 0x030303);
	framebuffer::basecolor black("black", 0x000000);
	framebuffer::basecolor gray0("gray0", 0x000000);
	framebuffer::basecolor grey0("grey0", 0x000000);
}
