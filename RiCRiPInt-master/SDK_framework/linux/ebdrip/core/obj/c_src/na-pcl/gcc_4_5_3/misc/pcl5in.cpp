% PCL5 input operator
pcl5exec OPERATOR
% Update PCL 5 factory defaults
setpcl5params OPERATOR DICT(1183615869 internaldict)
% PCL5 image processing operator. This is used as a DataSource
% procedure for dealing with PCL5 rasters.
pcl5imageread OPERATOR
debug_pcl5
% PCL5PrintEnviroment
% Entries for dict parameter to pcl5exec
BackChannel
Copies
Courier
Duplex
FontNumber
FontSource
LineTermination
Pitch
PointSize
SymbolSet
PCL5Mode
% Values for PCL5Mode
PCL5e
PCL5c
% PCL5PrintEnvironment
% Entries for pagedevice keys that are of interest to PCL5
Duplex
Jog
HWResolution
LeadingEdge
PageSize
Tumble
% PCL5PrintEnviroment
% Entries for PCL5 specific ExtraPageDeviceKeys
PCL5DefaultLogicalPage
PCL5DefaultMediaType
PCL5DefaultPageSize
PCL5DefaultPaperSource
PCL5DefaultPrintableArea
PCL5LogicalPage
PCL5MediaType
PCL5OutputBin
PCL5PageLength
PCL5PageSize
PCL5PaperSource
PCL5PrintableArea
PCL5RequestedPageSize
PCL5VMI
% Entries for shared PCLXL and PCL5 ExtraPageDeviceKeys
PCLDefaultDuplex
PCLDefaultOrientation
PCLDefaultPageSize
PCLDefaultTumble
PCLOrientation
LB % Label
% Entries for dict parameter to setpcl5params
TwoByteCharacterSupport
VirtualDeviceSpace
Default
Other
% Names used by implementation
DeviceCMY
DeviceGray
DeviceCMYK
DeviceRGB
OverrideRGB
HWResolution
Indexed
PageSize
SubFileDecode
VMode
WMode
\043copies NAME(copies)
image
imagemask
