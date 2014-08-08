%!PS-Adobe-3.0 Resource-CMap
%%DocumentNeededResources: ProcSet (CIDInit)
%%IncludeResource: ProcSet (CIDInit)
%%BeginResource: CMap (Adobe-Japan1-PS-V)
%%Title: (Adobe-Japan1-PS-V Adobe Japan1 2)
%%Version: 7.001
%%Copyright: -----------------------------------------------------------
%%Copyright: Copyright 1990-1997 Adobe Systems Incorporated.
%%Copyright: All Rights Reserved.
%%Copyright:
%%Copyright: Patents Pending
%%Copyright:
%%Copyright: NOTICE: All information contained herein is the property
%%Copyright: of Adobe Systems Incorporated.
%%Copyright:
%%Copyright: Permission is granted for redistribution of this file
%%Copyright: provided this copyright notice is maintained intact and
%%Copyright: that the contents of this file are not altered in any
%%Copyright: way from its original form.
%%Copyright:
%%Copyright: PostScript and Display PostScript are trademarks of
%%Copyright: Adobe Systems Incorporated which may be registered in
%%Copyright: certain jurisdictions.
%%Copyright: -----------------------------------------------------------
%%EndComments

% This CMap is used for mapping from CIDs to encodings that are available
% on a Japanese PostScript Printer for vertical fonts.
% The ranges in the CMap maps CIDs to following font numbers
%
% font 0  - character codes in RKSJ-V
% font 1  - proportional roman ascii codes  *****
% font 2  - character codes in Ext-RKSJ-V only (not in RKSJ-V)
% font 3  - CIDs that are not in RKSJ-V or Ext-RKSJ-V
% font 4  - CIDs that horizontal glyphs in RSKJ-V

/CIDInit /ProcSet findresource begin

12 dict begin

begincmap

/CIDSystemInfo 3 dict dup begin
  /Registry (Adobe) def
  /Ordering (Japan1) def
  /Supplement 2 def
end def

/CMapName /Adobe-Japan1-PS-V def

/CMapVersion 7.001 def
/CMapType 1 def

/XUID [1 10 25335 1212] def

/WMode 0 def

1 begincodespacerange
  <0000> <FFFF>
endcodespacerange

3 usefont    % Subset font
%Use Identity mapping
1 beginbfrange
<0000> <ffff> <0000>
endbfrange

0 usefont % RKSJ-V
101 beginbfrange
<0000> <0000>	<8140>
<00E7> <00FF>	<20>
<0100> <0145>	<39>
<0146> <0185>	<A0>
<0279> <0279>	<8140>
<027C> <0288>	<8143>
<028B> <0293>	<8152>
<0297> <0298>	<815E>
<029E> <02A1>	<8165>
<02B4> <02B7>	<817B>
<02B8> <02B8>	<8180>
<02BA> <02E4>	<8182>
<02E5> <02EC>	<81B8>
<02ED> <02F3>	<81C8>
<02F4> <02FF>	<81DA>
<0300> <0302>	<81E6>
<0303> <030A>	<81F0>
<030B> <030B>	<81FC>
<030C> <0315>	<824F>
<0316> <032F>	<8260>
<0330> <0349>	<8281>
<034B> <034B>	<82A0>
<034D> <034D>	<82A2>
<034F> <034F>	<82A4>
<0351> <0351>	<82A6>
<0353> <036B>	<82A8>
<036D> <038B>	<82C2>
<038D> <038D>	<82E2>
<038F> <038F>	<82E4>
<0391> <0396>	<82E6>
<0398> <039C>	<82ED>
<039E> <039E>	<8341>
<03A0> <03A0>	<8343>
<03A2> <03A2>	<8345>
<03A4> <03A4>	<8347>
<03A6> <03BE>	<8349>
<03C0> <03DB>	<8363>
<03DC> <03DE>	<8380>
<03E0> <03E0>	<8384>
<03E2> <03E2>	<8386>
<03E4> <03E9>	<8388>
<03EB> <03F0>	<838F>
<03F3> <03FF>	<839F>
<0400> <040A>	<83AC>
<040B> <0422>	<83BF>
<0423> <0443>	<8440>
<0444> <0452>	<8470>
<0453> <0464>	<8480>
<0465> <04C2>	<889F>
<04C3> <04FF>	<8940>
<0500> <0501>	<897D>
<0502> <057E>	<8980>
<057F> <05BD>	<8A40>
<05BE> <05FF>	<8A80>
<0600> <063A>	<8AC2>
<063B> <0679>	<8B40>
<067A> <06F6>	<8B80>
<06F7> <06FF>	<8C40>
<0700> <0735>	<8C49>
<0736> <07B2>	<8C80>
<07B3> <07F1>	<8D40>
<07F2> <07FF>	<8D80>
<0800> <086E>	<8D8E>
<086F> <08AD>	<8E40>
<08AE> <08FF>	<8E80>
<0900> <092A>	<8ED2>
<092B> <0969>	<8F40>
<096A> <09E6>	<8F80>
<09E7> <09FF>	<9040>
<0A00> <0A25>	<9059>
<0A26> <0AA2>	<9080>
<0AA3> <0AE1>	<9140>
<0AE2> <0AFF>	<9180>
<0B00> <0B5E>	<919E>
<0B5F> <0B9D>	<9240>
<0B9E> <0BFF>	<9280>
<0C00> <0C1A>	<92E2>
<0C1B> <0C59>	<9340>
<0C5A> <0CD6>	<9380>
<0CD7> <0CFF>	<9440>
<0D00> <0D15>	<9469>
<0D16> <0D92>	<9480>
<0D93> <0DD1>	<9540>
<0DD2> <0DFF>	<9580>
<0E00> <0E4E>	<95AE>
<0E4F> <0E8D>	<9640>
<0E8E> <0EFF>	<9680>
<0F00> <0F0A>	<96F2>
<0F0B> <0F49>	<9740>
<0F4A> <0FC6>	<9780>
<0FC7> <0FF9>	<9840>
<0FFA> <0FFF>	<989F>
<1000> <1057>	<98A5>
<1058> <1096>	<9940>
<1097> <10FF>	<9980>
<1100> <1113>	<99E9>
<1114> <1152>	<9A40>
<1153> <11CF>	<9A80>
<11D0> <11FF>	<9B40>
<1200> <120E>	<9B70>
<120F> <128B>	<9B80>
endbfrange
100 beginbfrange
<128C> <12CA>	<9C40>
<12CB> <12FF>	<9C80>
<1300> <1347>	<9CB5>
<1348> <1386>	<9D40>
<1387> <13FF>	<9D80>
<1400> <1403>	<9DF9>
<1404> <1442>	<9E40>
<1443> <14BF>	<9E80>
<14C0> <14FE>	<9F40>
<14FF> <14FF>	<9F80>
<1500> <157B>	<9F81>
<157C> <15BA>	<E040>
<15BB> <15FF>	<E080>
<1600> <1637>	<E0C5>
<1638> <1676>	<E140>
<1677> <16F3>	<E180>
<16F4> <16FF>	<E240>
<1700> <1732>	<E24C>
<1733> <17AF>	<E280>
<17B0> <17EE>	<E340>
<17EF> <17FF>	<E380>
<1800> <186B>	<E391>
<186C> <18AA>	<E440>
<18AB> <18FF>	<E480>
<1900> <1927>	<E4D5>
<1928> <1966>	<E540>
<1967> <19E3>	<E580>
<19E4> <19FF>	<E640>
<1A00> <1A22>	<E65C>
<1A23> <1A9F>	<E680>
<1AA0> <1ADE>	<E740>
<1ADF> <1AFF>	<E780>
<1B00> <1B5B>	<E7A1>
<1B5C> <1B9A>	<E840>
<1B9B> <1BFF>	<E880>
<1C00> <1C17>	<E8E5>
<1C18> <1C56>	<E940>
<1C57> <1CD3>	<E980>
<1CD4> <1CFF>	<EA40>
<1D00> <1D12>	<EA6C>
<1D13> <1D35>	<EA80>
<1D37> <1D37>	<849F>
<1D38> <1D38>	<84AA>
<1D39> <1D39>	<84A0>
<1D3A> <1D3A>	<84AB>
<1D43> <1D43>	<84A1>
<1D46> <1D46>	<84AC>
<1D47> <1D47>	<84A2>
<1D4A> <1D4A>	<84AD>
<1D4B> <1D4B>	<84A4>
<1D4E> <1D4E>	<84AF>
<1D4F> <1D4F>	<84A3>
<1D52> <1D52>	<84AE>
<1D53> <1D53>	<84A5>
<1D54> <1D54>	<84BA>
<1D57> <1D57>	<84B5>
<1D5A> <1D5A>	<84B0>
<1D5B> <1D5B>	<84A7>
<1D5C> <1D5C>	<84BC>
<1D5F> <1D5F>	<84B7>
<1D62> <1D62>	<84B2>
<1D63> <1D63>	<84A6>
<1D66> <1D66>	<84B6>
<1D67> <1D67>	<84BB>
<1D6A> <1D6A>	<84B1>
<1D6B> <1D6B>	<84A8>
<1D6E> <1D6E>	<84B8>
<1D6F> <1D6F>	<84BD>
<1D72> <1D72>	<84B3>
<1D73> <1D73>	<84A9>
<1D76> <1D76>	<84B9>
<1D79> <1D79>	<84BE>
<1D82> <1D82>	<84B4>
<1ECF> <1ED0>	<8141>
<1ED1> <1ED2>	<8150>
<1ED3> <1ED5>	<815B>
<1ED6> <1EDA>	<8160>
<1EDB> <1EEC>	<8169>
<1EED> <1EED>	<8181>
<1EEE> <1EEE>	<829F>
<1EEF> <1EEF>	<82A1>
<1EF0> <1EF0>	<82A3>
<1EF1> <1EF1>	<82A5>
<1EF2> <1EF2>	<82A7>
<1EF3> <1EF3>	<82C1>
<1EF4> <1EF4>	<82E1>
<1EF5> <1EF5>	<82E3>
<1EF6> <1EF6>	<82E5>
<1EF7> <1EF7>	<82EC>
<1EF8> <1EF8>	<8340>
<1EF9> <1EF9>	<8342>
<1EFA> <1EFA>	<8344>
<1EFB> <1EFB>	<8346>
<1EFC> <1EFC>	<8348>
<1EFD> <1EFD>	<8362>
<1EFE> <1EFE>	<8383>
<1EFF> <1EFF>	<8385>
<1F00> <1F00>	<8387>
<1F01> <1F01>	<838E>
<1F02> <1F03>	<8395>
endbfrange

1 usefont  % proportional roman
1 beginbfrange
<0001> <005f> <20>
endbfrange

2 usefont  % Ext-RKSJ-V Only

100 beginbfrange
<0186> <0186>	<8580>
<0187> <01A5>	<85DE>
<01A6> <01E4>	<8640>
<01E5> <01F6>	<8680>
<01F7> <01FF>	<8693>
<0200> <0202>	<869C>
<1D36> <1D36>	<8189>
<1D3B> <1D42>	<86A6>
<1D44> <1D45>	<86AF>
<1D48> <1D49>	<86B3>
<1D4C> <1D4D>	<86B7>
<1D50> <1D51>	<86BB>
<1D55> <1D56>	<86C0>
<1D58> <1D59>	<86C3>
<1D5D> <1D5E>	<86C8>
<1D60> <1D61>	<86CB>
<1D64> <1D65>	<86CF>
<1D68> <1D69>	<86D3>
<1D6C> <1D6D>	<86D7>
<1D70> <1D71>	<86DB>
<1D74> <1D75>	<86DF>
<1D77> <1D78>	<86E2>
<1D7A> <1D81>	<86E5>
<1D83> <1DA0>	<8740>
<1DB1> <1DB7>	<876F>
<1DBA> <1DC7>	<8782>
<1DC8> <1DCE>	<8793>
<1DCF> <1DD0>	<879B>
<1DD1> <1DD1>	<88A0>
<1DD2> <1DD2>	<88B9>
<1DD3> <1DD3>	<88EC>
<1DD4> <1DD4>	<88F1>
<1DD5> <1DD5>	<88FA>
<1DD6> <1DD6>	<8949>
<1DD7> <1DD7>	<8954>
<1DD8> <1DD8>	<8958>
<1DD9> <1DDA>	<895B>
<1DDB> <1DDB>	<8961>
<1DDC> <1DDC>	<898B>
<1DDD> <1DDD>	<89A6>
<1DDE> <1DDE>	<89A8>
<1DDF> <1DDF>	<89DE>
<1DE0> <1DE0>	<89F8>
<1DE1> <1DE1>	<89FB>
<1DE2> <1DE2>	<8A41>
<1DE3> <1DE3>	<8A85>
<1DE4> <1DE4>	<8A8B>
<1DE5> <1DE5>	<8A93>
<1DE6> <1DE6>	<8A9A>
<1DE7> <1DE7>	<8AC0>
<1DE8> <1DE8>	<8ACB>
<1DE9> <1DE9>	<8AE3>
<1DEA> <1DEA>	<8B4A>
<1DEB> <1DEB>	<8B5F>
<1DEC> <1DEC>	<8BA0>
<1DED> <1DED>	<8BA8>
<1DEE> <1DEE>	<8BCD>
<1DEF> <1DEF>	<8BEB>
<1DF0> <1DF0>	<8BF2>
<1DF1> <1DF1>	<8BF9>
<1DF2> <1DF2>	<8BFB>
<1DF3> <1DF3>	<8C43>
<1DF4> <1DF4>	<8C56>
<1DF5> <1DF5>	<8C64>
<1DF6> <1DF6>	<8C6D>
<1DF7> <1DF7>	<8C71>
<1DF8> <1DF8>	<8C74>
<1DF9> <1DF9>	<8C84>
<1DFA> <1DFA>	<8C91>
<1DFB> <1DFB>	<8C99>
<1DFC> <1DFC>	<8C9E>
<1DFD> <1DFD>	<8CB2>
<1DFE> <1DFE>	<8CBF>
<1DFF> <1DFF>	<8D4A>
<1E00> <1E00>	<8D56>
<1E01> <1E01>	<8D61>
<1E02> <1E02>	<8D8D>
<1E03> <1E03>	<8D94>
<1E04> <1E04>	<8D99>
<1E05> <1E05>	<8DD1>
<1E06> <1E06>	<8DE5>
<1E07> <1E07>	<8DF2>
<1E08> <1E08>	<8E46>
<1E09> <1E09>	<8E49>
<1E0A> <1E0A>	<8E4B>
<1E0B> <1E0B>	<8E58>
<1E0C> <1E0C>	<8EB6>
<1E0D> <1E0D>	<8EC6>
<1E0E> <1E0E>	<8ED5>
<1E0F> <1E10>	<8EDB>
<1E11> <1E11>	<8F4A>
<1E12> <1E12>	<8F55>
<1E13> <1E14>	<8F8C>
<1E15> <1E16>	<8F92>
<1E17> <1E17>	<8FA3>
<1E18> <1E18>	<8FB1>
<1E19> <1E19>	<8FBD>
<1E1A> <1E1A>	<8FD3>
<1E1B> <1E1B>	<8FDD>
<1E1C> <1E1C>	<8FE2>
endbfrange
100 beginbfrange
<1E1D> <1E1D>	<9049>
<1E1E> <1E1E>	<9078>
<1E1F> <1E1F>	<9080>
<1E20> <1E20>	<9089>
<1E21> <1E21>	<90A0>
<1E22> <1E22>	<90C0>
<1E23> <1E23>	<90E4>
<1E24> <1E25>	<90EF>
<1E26> <1E27>	<90F7>
<1E28> <1E28>	<9146>
<1E29> <1E29>	<9158>
<1E2A> <1E2A>	<916B>
<1E2B> <1E2B>	<916E>
<1E2C> <1E2C>	<917E>
<1E2D> <1E2D>	<9189>
<1E2E> <1E2E>	<91BB>
<1E2F> <1E2F>	<91CB>
<1E30> <1E30>	<91DA>
<1E31> <1E31>	<91E1>
<1E32> <1E32>	<91ED>
<1E33> <1E34>	<91F3>
<1E35> <1E35>	<91FB>
<1E36> <1E36>	<9246>
<1E37> <1E38>	<9248>
<1E39> <1E3A>	<924C>
<1E3B> <1E3B>	<925C>
<1E3C> <1E3C>	<9290>
<1E3D> <1E3D>	<9295>
<1E3E> <1E3E>	<929C>
<1E3F> <1E3F>	<92BB>
<1E40> <1E40>	<92C6>
<1E41> <1E41>	<92C8>
<1E42> <1E42>	<92CB>
<1E43> <1E43>	<92CD>
<1E44> <1E44>	<9341>
<1E45> <1E45>	<9346>
<1E46> <1E46>	<934D>
<1E47> <1E47>	<9355>
<1E48> <1E48>	<935E>
<1E49> <1E49>	<9367>
<1E4A> <1E4A>	<936A>
<1E4B> <1E4C>	<9370>
<1E4D> <1E4D>	<9384>
<1E4E> <1E4E>	<9398>
<1E4F> <1E4F>	<93BC>
<1E50> <1E50>	<93C0>
<1E51> <1E52>	<93D2>
<1E53> <1E54>	<93D9>
<1E55> <1E55>	<93DF>
<1E56> <1E57>	<93E4>
<1E58> <1E58>	<93E8>
<1E59> <1E59>	<9448>
<1E5A> <1E5A>	<9458>
<1E5B> <1E5B>	<9476>
<1E5C> <1E5C>	<9487>
<1E5D> <1E5D>	<9489>
<1E5E> <1E5E>	<948D>
<1E5F> <1E5F>	<94A2>
<1E60> <1E60>	<94AC>
<1E61> <1E61>	<94AE>
<1E62> <1E62>	<94D2>
<1E63> <1E63>	<94E0>
<1E64> <1E64>	<94F3>
<1E65> <1E66>	<9541>
<1E67> <1E67>	<954E>
<1E68> <1E68>	<9551>
<1E69> <1E69>	<9554>
<1E6A> <1E6A>	<955F>
<1E6B> <1E6B>	<956D>
<1E6C> <1E6C>	<9570>
<1E6D> <1E6D>	<95C1>
<1E6E> <1E6E>	<95CB>
<1E6F> <1E6F>	<95D8>
<1E70> <1E70>	<95F7>
<1E71> <1E71>	<9641>
<1E72> <1E72>	<9648>
<1E73> <1E73>	<966A>
<1E74> <1E74>	<9690>
<1E75> <1E75>	<96CB>
<1E76> <1E76>	<96D7>
<1E77> <1E77>	<96DD>
<1E78> <1E78>	<96E0>
<1E79> <1E79>	<96F8>
<1E7A> <1E7A>	<96FA>
<1E7B> <1E7B>	<96FC>
<1E7C> <1E7C>	<9751>
<1E7D> <1E7D>	<976F>
<1E7E> <1E7E>	<9773>
<1E7F> <1E7F>	<9789>
<1E80> <1E80>	<97C9>
<1E81> <1E82>	<97F8>
<1E83> <1E83>	<9840>
<1E84> <1E84>	<9850>
<1E85> <1E85>	<9858>
<1E86> <1E86>	<995C>
<1E87> <1E87>	<9966>
<1E88> <1E88>	<996A>
<1E89> <1E89>	<996C>
<1E8A> <1E8A>	<9A4F>
<1E8B> <1E8B>	<9A59>
endbfrange
82 beginbfrange
<1E8C> <1E8C>	<9A6F>
<1E8D> <1E8D>	<9A7D>
<1E8E> <1E8E>	<9A8B>
<1E8F> <1E8F>	<9AC2>
<1E90> <1E90>	<9B5C>
<1E91> <1E91>	<9B83>
<1E92> <1E92>	<9BA0>
<1E93> <1E93>	<9BF0>
<1E94> <1E94>	<9CA2>
<1E95> <1E95>	<9D80>
<1E96> <1E96>	<9D8C>
<1E97> <1E97>	<9DB7>
<1E98> <1E98>	<9DCB>
<1E99> <1E99>	<9E64>
<1E9A> <1E9A>	<9E69>
<1E9B> <1E9B>	<9E8B>
<1E9C> <1E9C>	<9E94>
<1E9D> <1E9D>	<9FCE>
<1E9E> <1E9E>	<E093>
<1E9F> <1E9F>	<E0A4>
<1EA0> <1EA0>	<E0DD>
<1EA1> <1EA1>	<E14A>
<1EA2> <1EA3>	<E14F>
<1EA4> <1EA4>	<E1A9>
<1EA5> <1EA5>	<E1ED>
<1EA6> <1EA6>	<E269>
<1EA7> <1EA7>	<E273>
<1EA8> <1EA8>	<E2B7>
<1EA9> <1EA9>	<E2E2>
<1EAA> <1EAA>	<E2EC>
<1EAB> <1EAB>	<E358>
<1EAC> <1EAC>	<E35A>
<1EAD> <1EAD>	<E365>
<1EAE> <1EAE>	<E3C4>
<1EAF> <1EAF>	<E484>
<1EB0> <1EB0>	<E489>
<1EB1> <1EB1>	<E492>
<1EB2> <1EB2>	<E4B2>
<1EB3> <1EB3>	<E4B9>
<1EB4> <1EB4>	<E4F2>
<1EB5> <1EB5>	<E55B>
<1EB6> <1EB6>	<E5A5>
<1EB7> <1EB7>	<E5BB>
<1EB8> <1EB8>	<E5ED>
<1EB9> <1EB9>	<E651>
<1EBA> <1EBA>	<E686>
<1EBB> <1EBB>	<E696>
<1EBC> <1EBC>	<E6E7>
<1EBD> <1EBD>	<E6F2>
<1EBE> <1EBE>	<E76D>
<1EBF> <1EBF>	<E78C>
<1EC0> <1EC0>	<E78E>
<1EC1> <1EC1>	<E7A7>
<1EC2> <1EC2>	<E7BB>
<1EC3> <1EC3>	<E7D5>
<1EC4> <1EC4>	<E885>
<1EC5> <1EC5>	<E8B1>
<1EC6> <1EC6>	<E8C3>
<1EC7> <1EC7>	<E8CF>
<1EC8> <1EC8>	<E8D5>
<1EC9> <1EC9>	<E8F3>
<1ECA> <1ECA>	<E9AB>
<1ECB> <1ECB>	<E9BA>
<1ECC> <1ECC>	<E9CC>
<1ECD> <1ECD>	<EA70>
<1ECE> <1ECE>	<EA9D>
<1F04> <1F13>	<875F>
<1F14> <1F15>	<8780>
<1F45> <1F47>	<EEFA>
<1F9C> <1FA5>	<EEEF>
<204C> <204C>	<8143>
<204D> <204D>	<818B>
<204E> <204E>	<81AC>
<204F> <204F>	<814B>
<2050> <2050>	<814A>
<2051> <2051>	<818C>
<2052> <2052>	<8144>
<2054> <2054>	<8166>
<2056> <2056>	<8168>
<2057> <2057>	<8167>
<2059> <2059>	<8165>
<205B> <205B>	<818D>
endbfrange

4 usefont % codes in RKSJ-H 
27 beginbfrange
<027A> <027B>	<8141>
<0289> <028A>	<8150>
<0294> <0296>	<815B>
<0299> <029D>	<8160>
<02A2> <02B3>	<8169>
<02B9> <02B9>	<8181>
<034A> <034A>	<829F>
<034C> <034C>	<82A1>
<034E> <034E>	<82A3>
<0350> <0350>	<82A5>
<0352> <0352>	<82A7>
<036C> <036C>	<82C1>
<038C> <038C>	<82E1>
<038E> <038E>	<82E3>
<0390> <0390>	<82E5>
<0397> <0397>	<82EC>
<039D> <039D>	<8340>
<039F> <039F>	<8342>
<03A1> <03A1>	<8344>
<03A3> <03A3>	<8346>
<03A5> <03A5>	<8348>
<03BF> <03BF>	<8362>
<03DF> <03DF>	<8383>
<03E1> <03E1>	<8385>
<03E3> <03E3>	<8387>
<03EA> <03EA>	<838E>
<03F1> <03F2>	<8395>
endbfrange

endcmap
CMapName currentdict /CMap defineresource pop
end
end

%%EndResource
%%EOF
