<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="16" fill="1" visible="no" active="no"/>
<layer number="3" name="Route3" color="17" fill="1" visible="no" active="no"/>
<layer number="4" name="Route4" color="18" fill="1" visible="no" active="no"/>
<layer number="5" name="Route5" color="19" fill="1" visible="no" active="no"/>
<layer number="6" name="Route6" color="25" fill="1" visible="no" active="no"/>
<layer number="7" name="Route7" color="26" fill="1" visible="no" active="no"/>
<layer number="8" name="Route8" color="27" fill="1" visible="no" active="no"/>
<layer number="9" name="Route9" color="28" fill="1" visible="no" active="no"/>
<layer number="10" name="Route10" color="29" fill="1" visible="no" active="no"/>
<layer number="11" name="Route11" color="30" fill="1" visible="no" active="no"/>
<layer number="12" name="Route12" color="20" fill="1" visible="no" active="no"/>
<layer number="13" name="Route13" color="21" fill="1" visible="no" active="no"/>
<layer number="14" name="Route14" color="22" fill="1" visible="no" active="no"/>
<layer number="15" name="Route15" color="23" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="5" fill="1" visible="yes" active="yes"/>
<layer number="250" name="Descript" color="3" fill="1" visible="no" active="no"/>
<layer number="251" name="SMDround" color="12" fill="11" visible="no" active="no"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="BW-Active" urn="urn:adsk.eagle:library:33783073">
<packages>
<package name="POWERPAK-SO8" urn="urn:adsk.eagle:footprint:39904257/2" library_version="41">
<smd name="1" x="-2.72" y="1.905" dx="1.37" dy="0.65" layer="1"/>
<smd name="2" x="-2.72" y="0.635" dx="1.37" dy="0.65" layer="1"/>
<smd name="3" x="-2.72" y="-0.635" dx="1.37" dy="0.65" layer="1"/>
<smd name="4" x="-2.72" y="-1.905" dx="1.37" dy="0.65" layer="1"/>
<smd name="5-8" x="1.105" y="0" dx="4.6" dy="4.5" layer="1"/>
<text x="-2.54" y="2.921" size="1.016" layer="25">&gt;NAME</text>
<text x="-2.54" y="-3.937" size="1.016" layer="27">&gt;VALUE</text>
<wire x1="-3.125" y1="-2.63" x2="3.125" y2="-2.63" width="0.127" layer="21"/>
<wire x1="-3.125" y1="2.63" x2="3.125" y2="2.63" width="0.127" layer="21"/>
</package>
</packages>
<packages3d>
<package3d name="POWERPAK-SO8" urn="urn:adsk.eagle:package:39904262/3" type="model" library_version="41">
<packageinstances>
<packageinstance name="POWERPAK-SO8"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="N-MOSFET" urn="urn:adsk.eagle:symbol:33783106/1" library_version="41">
<wire x1="0.762" y1="0.762" x2="0.762" y2="0" width="0.254" layer="94"/>
<wire x1="0.762" y1="0" x2="0.762" y2="-0.762" width="0.254" layer="94"/>
<wire x1="0.762" y1="3.175" x2="0.762" y2="2.54" width="0.254" layer="94"/>
<wire x1="0.762" y1="2.54" x2="0.762" y2="1.905" width="0.254" layer="94"/>
<wire x1="0.762" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="2.54" y1="0" x2="2.54" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="0.762" y1="-1.905" x2="0.762" y2="-2.54" width="0.254" layer="94"/>
<wire x1="0.762" y1="-2.54" x2="0.762" y2="-3.175" width="0.254" layer="94"/>
<wire x1="0" y1="2.54" x2="0" y2="-2.54" width="0.254" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="0.762" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="3.81" y1="2.54" x2="3.81" y2="0.508" width="0.1524" layer="94"/>
<wire x1="3.81" y1="0.508" x2="3.81" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="3.81" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="0.762" y1="2.54" x2="3.81" y2="2.54" width="0.1524" layer="94"/>
<wire x1="4.572" y1="0.762" x2="4.318" y2="0.508" width="0.1524" layer="94"/>
<wire x1="4.318" y1="0.508" x2="3.81" y2="0.508" width="0.1524" layer="94"/>
<wire x1="3.81" y1="0.508" x2="3.302" y2="0.508" width="0.1524" layer="94"/>
<wire x1="3.302" y1="0.508" x2="3.048" y2="0.254" width="0.1524" layer="94"/>
<circle x="2.54" y="-2.54" radius="0.3592" width="0" layer="94"/>
<circle x="2.54" y="2.54" radius="0.3592" width="0" layer="94"/>
<text x="-11.43" y="0" size="1.778" layer="96">&gt;VALUE</text>
<text x="-11.43" y="2.54" size="1.778" layer="95">&gt;NAME</text>
<pin name="S" x="2.54" y="-5.08" visible="off" length="short" direction="pas" rot="R90"/>
<pin name="G" x="-2.54" y="-2.54" visible="off" length="short" direction="pas"/>
<pin name="D" x="2.54" y="5.08" visible="off" length="short" direction="pas" rot="R270"/>
<polygon width="0.1524" layer="94">
<vertex x="3.81" y="0.508"/>
<vertex x="3.302" y="-0.254"/>
<vertex x="4.318" y="-0.254"/>
</polygon>
<polygon width="0.1524" layer="94">
<vertex x="1.016" y="0"/>
<vertex x="2.032" y="0.762"/>
<vertex x="2.032" y="-0.762"/>
</polygon>
</symbol>
</symbols>
<devicesets>
<deviceset name="POWERPAK-SO8-N-MOSFET" urn="urn:adsk.eagle:component:39904270/3" prefix="Q" uservalue="yes" library_version="41">
<gates>
<gate name="G$1" symbol="N-MOSFET" x="0" y="0" swaplevel="2"/>
</gates>
<devices>
<device name="" package="POWERPAK-SO8">
<connects>
<connect gate="G$1" pin="D" pad="5-8"/>
<connect gate="G$1" pin="G" pad="4"/>
<connect gate="G$1" pin="S" pad="1 2 3"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:39904262/3"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="BW-PassiveMechanical" urn="urn:adsk.eagle:library:33858467">
<packages>
<package name="XRCGB" urn="urn:adsk.eagle:footprint:39955096/1" library_version="28">
<smd name="1" x="-0.775" y="-0.6" dx="0.95" dy="0.9" layer="1"/>
<smd name="2" x="0.775" y="-0.6" dx="0.95" dy="0.9" layer="1"/>
<smd name="3" x="0.775" y="0.6" dx="0.95" dy="0.9" layer="1"/>
<smd name="4" x="-0.775" y="0.6" dx="0.95" dy="0.9" layer="1"/>
<wire x1="-1" y1="0.8" x2="1" y2="0.8" width="0.1524" layer="51"/>
<wire x1="1" y1="0.8" x2="1" y2="-0.8" width="0.1524" layer="51"/>
<wire x1="1" y1="-0.8" x2="-1" y2="-0.8" width="0.1524" layer="51"/>
<wire x1="-1" y1="-0.8" x2="-1" y2="0.8" width="0.1524" layer="51"/>
<wire x1="-0.1" y1="0.1" x2="0.1" y2="-0.1" width="0.1524" layer="21"/>
<text x="-1.3" y="1.3" size="1.016" layer="25">&gt;NAME</text>
<text x="-1.3" y="-2.3" size="1.016" layer="27">&gt;VALUE</text>
</package>
</packages>
<packages3d>
<package3d name="XRCGB" urn="urn:adsk.eagle:package:39955097/2" type="model" library_version="28">
<description>Oscillator Corner Concave, 2.00 X 1.60 X 0.70 mm body
&lt;p&gt;Oscillator Corner Concave package with body size 2.00 X 1.60 X 0.70 mm&lt;/p&gt;</description>
<packageinstances>
<packageinstance name="XRCGB"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="CRYSTAL" urn="urn:adsk.eagle:symbol:33858483/1" library_version="28">
<wire x1="1.016" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="0" x2="-1.016" y2="0" width="0.1524" layer="94"/>
<wire x1="-0.381" y1="1.524" x2="-0.381" y2="-1.524" width="0.254" layer="94"/>
<wire x1="-0.381" y1="-1.524" x2="0.381" y2="-1.524" width="0.254" layer="94"/>
<wire x1="0.381" y1="-1.524" x2="0.381" y2="1.524" width="0.254" layer="94"/>
<wire x1="0.381" y1="1.524" x2="-0.381" y2="1.524" width="0.254" layer="94"/>
<wire x1="1.016" y1="1.778" x2="1.016" y2="-1.778" width="0.254" layer="94"/>
<wire x1="-1.016" y1="1.778" x2="-1.016" y2="-1.778" width="0.254" layer="94"/>
<text x="-2.286" y="2.032" size="1.778" layer="95">&gt;NAME</text>
<text x="-2.286" y="-3.81" size="1.778" layer="96">&gt;VALUE</text>
<text x="-2.159" y="-1.143" size="0.8636" layer="93">1</text>
<text x="1.524" y="-1.143" size="0.8636" layer="93">2</text>
<pin name="2" x="2.54" y="0" visible="off" length="point" direction="pas" swaplevel="1" rot="R180"/>
<pin name="1" x="-2.54" y="0" visible="off" length="point" direction="pas" swaplevel="1"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="XRCGB-CRYSTAL" urn="urn:adsk.eagle:component:39955098/2" prefix="Y" uservalue="yes" library_version="28">
<gates>
<gate name="A" symbol="CRYSTAL" x="0" y="0"/>
</gates>
<devices>
<device name="" package="XRCGB">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="3"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:39955097/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="linear-technology" urn="urn:adsk.eagle:library:261">
<description>&lt;b&gt;Linear Technology Devices&lt;/b&gt;&lt;p&gt;
http://www.linear-tech.com&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="QFN3X3-6" urn="urn:adsk.eagle:footprint:16050/1" library_version="4">
<description>&lt;b&gt;16-Lead Plastic QFN (3mm × 3mm)&lt;/b&gt;&lt;p&gt;
Auto generated by &lt;i&gt;make-symbol-device-package-bsdl.ulp Rev. 44&lt;/i&gt;&lt;br&gt;
&lt;br&gt;
Source: http://cds.linear.com/docs/en/datasheet/3645f.pdf&lt;br&gt;</description>
<smd name="1" x="-1.4" y="0.75" dx="0.7" dy="0.3" layer="1" stop="no"/>
<smd name="2" x="-1.4" y="0.25" dx="0.7" dy="0.3" layer="1" stop="no"/>
<smd name="3" x="-1.4" y="-0.25" dx="0.7" dy="0.3" layer="1" stop="no"/>
<smd name="4" x="-1.4" y="-0.75" dx="0.7" dy="0.3" layer="1" stop="no"/>
<smd name="5" x="-0.75" y="-1.4" dx="0.3" dy="0.7" layer="1" stop="no"/>
<smd name="6" x="-0.25" y="-1.4" dx="0.3" dy="0.7" layer="1" stop="no"/>
<smd name="7" x="0.25" y="-1.4" dx="0.3" dy="0.7" layer="1" stop="no"/>
<smd name="8" x="0.75" y="-1.4" dx="0.3" dy="0.7" layer="1" stop="no"/>
<smd name="9" x="1.4" y="-0.75" dx="0.7" dy="0.3" layer="1" stop="no"/>
<smd name="10" x="1.4" y="-0.25" dx="0.7" dy="0.3" layer="1" stop="no"/>
<smd name="11" x="1.4" y="0.25" dx="0.7" dy="0.3" layer="1" stop="no"/>
<smd name="12" x="1.4" y="0.75" dx="0.7" dy="0.3" layer="1" stop="no"/>
<smd name="13" x="0.75" y="1.4" dx="0.3" dy="0.7" layer="1" stop="no"/>
<smd name="14" x="0.25" y="1.4" dx="0.3" dy="0.7" layer="1" stop="no"/>
<smd name="15" x="-0.25" y="1.4" dx="0.3" dy="0.7" layer="1" stop="no"/>
<smd name="16" x="-0.75" y="1.4" dx="0.3" dy="0.7" layer="1" stop="no"/>
<smd name="EXP" x="0" y="0" dx="1.45" dy="1.45" layer="1" stop="no"/>
<wire x1="-1.3484" y1="1.05" x2="-1.05" y2="1.3484" width="0.2032" layer="21"/>
<wire x1="-1.3984" y1="-1.3984" x2="1.3984" y2="-1.3984" width="0.2032" layer="21"/>
<wire x1="1.3984" y1="-1.3984" x2="1.3984" y2="1.3984" width="0.2032" layer="21"/>
<wire x1="1.3984" y1="1.3984" x2="-1.3984" y2="1.3984" width="0.2032" layer="21"/>
<wire x1="-1.3984" y1="1.3984" x2="-1.3984" y2="-1.3984" width="0.2032" layer="21"/>
<text x="-1.5" y="2.135" size="1.27" layer="25">&gt;NAME</text>
<text x="-1.5" y="-3.405" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-1.85" y1="0.55" x2="-1" y2="0.95" layer="29"/>
<rectangle x1="-1.85" y1="0.05" x2="-1" y2="0.45" layer="29"/>
<rectangle x1="-1.85" y1="-0.45" x2="-1" y2="-0.05" layer="29"/>
<rectangle x1="-1.85" y1="-0.95" x2="-1" y2="-0.55" layer="29"/>
<rectangle x1="-1.175" y1="-1.625" x2="-0.325" y2="-1.225" layer="29" rot="R90"/>
<rectangle x1="-0.675" y1="-1.625" x2="0.175" y2="-1.225" layer="29" rot="R90"/>
<rectangle x1="-0.175" y1="-1.625" x2="0.675" y2="-1.225" layer="29" rot="R90"/>
<rectangle x1="0.325" y1="-1.625" x2="1.175" y2="-1.225" layer="29" rot="R90"/>
<rectangle x1="1" y1="-0.95" x2="1.85" y2="-0.55" layer="29" rot="R180"/>
<rectangle x1="1" y1="-0.45" x2="1.85" y2="-0.05" layer="29" rot="R180"/>
<rectangle x1="1" y1="0.05" x2="1.85" y2="0.45" layer="29" rot="R180"/>
<rectangle x1="1" y1="0.55" x2="1.85" y2="0.95" layer="29" rot="R180"/>
<rectangle x1="0.325" y1="1.225" x2="1.175" y2="1.625" layer="29" rot="R270"/>
<rectangle x1="-0.175" y1="1.225" x2="0.675" y2="1.625" layer="29" rot="R270"/>
<rectangle x1="-0.675" y1="1.225" x2="0.175" y2="1.625" layer="29" rot="R270"/>
<rectangle x1="-1.175" y1="1.225" x2="-0.325" y2="1.625" layer="29" rot="R270"/>
<rectangle x1="-0.8" y1="-0.8" x2="0.8" y2="0.8" layer="29"/>
</package>
<package name="MSOP12" urn="urn:adsk.eagle:footprint:16051/1" library_version="4">
<description>&lt;b&gt;MSE Package&lt;/b&gt; 12-Lead Plastic MSOP  Exposed Die Pad&lt;p&gt;
(Reference LTC DWG # 05-08-1666 Rev D)&lt;br&gt;
Source: http://cds.linear.com/docs/en/datasheet/3645f.pdf&lt;br&gt;
Auto generated by &lt;i&gt;make-symbol-device-package-bsdl.ulp Rev. 44&lt;/i&gt;&lt;br&gt;</description>
<smd name="1" x="-2.1625" y="1.625" dx="0.9" dy="0.42" layer="1" stop="no"/>
<smd name="2" x="-2.1625" y="0.975" dx="0.9" dy="0.42" layer="1" stop="no"/>
<smd name="3" x="-2.1625" y="0.325" dx="0.9" dy="0.42" layer="1" stop="no"/>
<smd name="4" x="-2.1625" y="-0.325" dx="0.9" dy="0.42" layer="1" stop="no"/>
<smd name="5" x="-2.1625" y="-0.975" dx="0.9" dy="0.42" layer="1" stop="no"/>
<smd name="6" x="-2.1625" y="-1.625" dx="0.9" dy="0.42" layer="1" stop="no"/>
<smd name="7" x="2.15" y="-1.625" dx="0.9" dy="0.42" layer="1" stop="no"/>
<smd name="8" x="2.15" y="-0.975" dx="0.9" dy="0.42" layer="1" stop="no"/>
<smd name="9" x="2.15" y="-0.325" dx="0.9" dy="0.42" layer="1" stop="no"/>
<smd name="10" x="2.15" y="0.325" dx="0.9" dy="0.42" layer="1" stop="no"/>
<smd name="11" x="2.15" y="0.975" dx="0.9" dy="0.42" layer="1" stop="no"/>
<smd name="12" x="2.15" y="1.625" dx="0.9" dy="0.42" layer="1" stop="no"/>
<smd name="EXP" x="0" y="0" dx="1.65" dy="2.85" layer="1"/>
<rectangle x1="-2.45" y1="1.435" x2="-1.5" y2="1.815" layer="51"/>
<rectangle x1="-2.45" y1="0.785" x2="-1.5" y2="1.165" layer="51"/>
<rectangle x1="-2.45" y1="0.135" x2="-1.5" y2="0.515" layer="51"/>
<rectangle x1="-2.45" y1="-0.515" x2="-1.5" y2="-0.135" layer="51"/>
<rectangle x1="-2.45" y1="-1.165" x2="-1.5" y2="-0.785" layer="51"/>
<rectangle x1="-2.45" y1="-1.815" x2="-1.5" y2="-1.435" layer="51"/>
<rectangle x1="1.5" y1="-1.815" x2="2.45" y2="-1.435" layer="51"/>
<rectangle x1="1.5" y1="-1.165" x2="2.45" y2="-0.785" layer="51"/>
<rectangle x1="1.5" y1="-0.515" x2="2.45" y2="-0.135" layer="51"/>
<rectangle x1="1.5" y1="0.135" x2="2.45" y2="0.515" layer="51"/>
<rectangle x1="1.5" y1="0.785" x2="2.45" y2="1.165" layer="51"/>
<rectangle x1="1.5" y1="1.435" x2="2.45" y2="1.815" layer="51"/>
<rectangle x1="-2.6625" y1="1.3875" x2="-1.675" y2="1.8625" layer="29"/>
<rectangle x1="-2.6625" y1="0.7375" x2="-1.675" y2="1.2125" layer="29"/>
<rectangle x1="-2.6625" y1="0.0875" x2="-1.675" y2="0.5625" layer="29"/>
<rectangle x1="-2.6625" y1="-0.5625" x2="-1.675" y2="-0.0875" layer="29"/>
<rectangle x1="-2.6625" y1="-1.2125" x2="-1.675" y2="-0.7375" layer="29"/>
<rectangle x1="-2.6625" y1="-1.8625" x2="-1.675" y2="-1.3875" layer="29"/>
<rectangle x1="1.675" y1="-1.8625" x2="2.6625" y2="-1.3875" layer="29" rot="R180"/>
<rectangle x1="1.675" y1="-1.2125" x2="2.6625" y2="-0.7375" layer="29" rot="R180"/>
<rectangle x1="1.675" y1="-0.5625" x2="2.6625" y2="-0.0875" layer="29" rot="R180"/>
<rectangle x1="1.675" y1="0.0875" x2="2.6625" y2="0.5625" layer="29" rot="R180"/>
<rectangle x1="1.675" y1="0.7375" x2="2.6625" y2="1.2125" layer="29" rot="R180"/>
<rectangle x1="1.675" y1="1.3875" x2="2.6625" y2="1.8625" layer="29" rot="R180"/>
<wire x1="-0.3" y1="1.8734" x2="0.3" y2="1.8734" width="0.2032" layer="21" curve="180"/>
<wire x1="-1.3984" y1="-1.8984" x2="1.3984" y2="-1.8984" width="0.2032" layer="21"/>
<wire x1="1.3984" y1="-1.8984" x2="1.3984" y2="1.8984" width="0.2032" layer="21"/>
<wire x1="1.3984" y1="1.8984" x2="-1.3984" y2="1.8984" width="0.2032" layer="21"/>
<wire x1="-1.3984" y1="1.8984" x2="-1.3984" y2="-1.8984" width="0.2032" layer="21"/>
<text x="-2.2" y="2.275" size="1.27" layer="25">&gt;NAME</text>
<text x="-2.3375" y="-3.6625" size="1.27" layer="27">&gt;VALUE</text>
</package>
</packages>
<packages3d>
<package3d name="QFN3X3-6" urn="urn:adsk.eagle:package:16080/1" type="box" library_version="4">
<description>16-Lead Plastic QFN (3mm × 3mm)
Auto generated by make-symbol-device-package-bsdl.ulp Rev. 44

Source: http://cds.linear.com/docs/en/datasheet/3645f.pdf</description>
<packageinstances>
<packageinstance name="QFN3X3-6"/>
</packageinstances>
</package3d>
<package3d name="MSOP12" urn="urn:adsk.eagle:package:16081/1" type="box" library_version="4">
<description>MSE Package 12-Lead Plastic MSOP  Exposed Die Pad
(Reference LTC DWG # 05-08-1666 Rev D)
Source: http://cds.linear.com/docs/en/datasheet/3645f.pdf
Auto generated by make-symbol-device-package-bsdl.ulp Rev. 44</description>
<packageinstances>
<packageinstance name="MSOP12"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="LT3645" urn="urn:adsk.eagle:symbol:16049/1" library_version="4">
<pin name="NPG" x="-10.16" y="0" length="short" direction="out"/>
<pin name="EN2" x="12.7" y="-5.08" length="short" direction="in" rot="R180"/>
<pin name="EN/UVLO" x="-10.16" y="7.62" length="short" direction="in"/>
<pin name="FB" x="12.7" y="2.54" length="short" direction="in" rot="R180"/>
<pin name="GND" x="-10.16" y="-17.78" length="short" direction="pwr"/>
<pin name="DA" x="12.7" y="5.08" length="short" direction="in" rot="R180"/>
<pin name="SW" x="12.7" y="10.16" length="short" direction="oc" rot="R180"/>
<pin name="BOOST" x="12.7" y="15.24" length="short" direction="in" rot="R180"/>
<pin name="VIN" x="-10.16" y="12.7" length="short" direction="in"/>
<pin name="VCC2" x="12.7" y="-7.62" length="short" direction="in" rot="R180"/>
<pin name="OUT2" x="12.7" y="-12.7" length="short" direction="out" rot="R180"/>
<pin name="FB2" x="12.7" y="-17.78" length="short" direction="in" rot="R180"/>
<pin name="GND@2" x="-10.16" y="-15.24" length="short" direction="pwr"/>
<wire x1="-7.62" y1="17.78" x2="-7.62" y2="-20.32" width="0.254" layer="94"/>
<wire x1="-7.62" y1="-20.32" x2="10.16" y2="-20.32" width="0.254" layer="94"/>
<wire x1="10.16" y1="-20.32" x2="10.16" y2="17.78" width="0.254" layer="94"/>
<wire x1="10.16" y1="17.78" x2="-7.62" y2="17.78" width="0.254" layer="94"/>
<text x="-7.62" y="19.05" size="1.778" layer="95">&gt;NAME</text>
<text x="-7.62" y="-22.86" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="LT3645" urn="urn:adsk.eagle:component:16124/2" prefix="IC" library_version="4">
<description>&lt;b&gt;36V 500mA Step-Down Regulator and 200mA LDO&lt;/b&gt;&lt;p&gt;
Source: http://cds.linear.com/docs/en/datasheet/3645f.pdf</description>
<gates>
<gate name="A" symbol="LT3645" x="0" y="0"/>
</gates>
<devices>
<device name="UD" package="QFN3X3-6">
<connects>
<connect gate="A" pin="BOOST" pad="10"/>
<connect gate="A" pin="DA" pad="8"/>
<connect gate="A" pin="EN/UVLO" pad="5"/>
<connect gate="A" pin="EN2" pad="4"/>
<connect gate="A" pin="FB" pad="6"/>
<connect gate="A" pin="FB2" pad="16"/>
<connect gate="A" pin="GND" pad="7"/>
<connect gate="A" pin="GND@2" pad="EXP"/>
<connect gate="A" pin="NPG" pad="3"/>
<connect gate="A" pin="OUT2" pad="15"/>
<connect gate="A" pin="SW" pad="9"/>
<connect gate="A" pin="VCC2" pad="14"/>
<connect gate="A" pin="VIN" pad="11"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:16080/1"/>
</package3dinstances>
<technologies>
<technology name="E">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
<technology name="I">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
</technologies>
</device>
<device name="MSE" package="MSOP12">
<connects>
<connect gate="A" pin="BOOST" pad="5"/>
<connect gate="A" pin="DA" pad="4"/>
<connect gate="A" pin="EN/UVLO" pad="1"/>
<connect gate="A" pin="EN2" pad="11"/>
<connect gate="A" pin="FB" pad="2"/>
<connect gate="A" pin="FB2" pad="10"/>
<connect gate="A" pin="GND" pad="3"/>
<connect gate="A" pin="GND@2" pad="EXP"/>
<connect gate="A" pin="NPG" pad="12"/>
<connect gate="A" pin="OUT2" pad="9"/>
<connect gate="A" pin="SW" pad="6"/>
<connect gate="A" pin="VCC2" pad="8"/>
<connect gate="A" pin="VIN" pad="7"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:16081/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="Q1" library="BW-Active" library_urn="urn:adsk.eagle:library:33783073" deviceset="POWERPAK-SO8-N-MOSFET" device="" package3d_urn="urn:adsk.eagle:package:39904262/3"/>
<part name="Y1" library="BW-PassiveMechanical" library_urn="urn:adsk.eagle:library:33858467" deviceset="XRCGB-CRYSTAL" device="" package3d_urn="urn:adsk.eagle:package:39955097/2"/>
<part name="IC1" library="linear-technology" library_urn="urn:adsk.eagle:library:261" deviceset="LT3645" device="UD" package3d_urn="urn:adsk.eagle:package:16080/1" technology="E" value=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="Q1" gate="G$1" x="35.56" y="30.48" smashed="yes">
<attribute name="VALUE" x="24.13" y="30.48" size="1.778" layer="96"/>
<attribute name="NAME" x="24.13" y="33.02" size="1.778" layer="95"/>
</instance>
<instance part="Y1" gate="A" x="35.56" y="10.16" smashed="yes">
<attribute name="NAME" x="33.274" y="12.192" size="1.778" layer="95"/>
<attribute name="VALUE" x="33.274" y="6.35" size="1.778" layer="96"/>
</instance>
<instance part="IC1" gate="A" x="60.96" y="22.86" smashed="yes">
<attribute name="NAME" x="53.34" y="41.91" size="1.778" layer="95"/>
<attribute name="VALUE" x="53.34" y="0" size="1.778" layer="96"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="Q1" gate="G$1" pin="D"/>
<wire x1="38.1" y1="35.56" x2="38.1" y2="38.1" width="0.1524" layer="91"/>
<wire x1="38.1" y1="38.1" x2="45.72" y2="38.1" width="0.1524" layer="91"/>
<pinref part="IC1" gate="A" pin="GND@2"/>
<wire x1="45.72" y1="38.1" x2="45.72" y2="10.16" width="0.1524" layer="91"/>
<wire x1="45.72" y1="10.16" x2="45.72" y2="7.62" width="0.1524" layer="91"/>
<wire x1="45.72" y1="7.62" x2="48.26" y2="7.62" width="0.1524" layer="91"/>
<pinref part="Y1" gate="A" pin="2"/>
<wire x1="48.26" y1="7.62" x2="50.8" y2="7.62" width="0.1524" layer="91"/>
<wire x1="38.1" y1="10.16" x2="45.72" y2="10.16" width="0.1524" layer="91"/>
<junction x="45.72" y="10.16"/>
<pinref part="IC1" gate="A" pin="GND"/>
<wire x1="48.26" y1="5.08" x2="50.8" y2="5.08" width="0.1524" layer="91"/>
<wire x1="48.26" y1="7.62" x2="48.26" y2="5.08" width="0.1524" layer="91"/>
<junction x="48.26" y="7.62"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
