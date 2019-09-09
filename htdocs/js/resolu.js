var userAgent = navigator.userAgent.toLowerCase();
var devices = new Array('nokia','iphone','blackberry','sony','lg',
'htc_tattoo','samsung','symbian','SymbianOS','elaine','palm',
'series60','windows ce','android','obigo','netfront',
'openwave','mobilexplorer','operamini');
function mobiDetect(userAgent, devices) {
for(var i = 0; i < devices.length; i++) {
if (userAgent.search(devices[i]) > 0) {
return true;
}
}
return false;
}

if (mobiDetect(userAgent, devices)) {
	document.write('<link rel="stylesheet" type="text/css" href="css/mobile/index.css">')
}else{
	document.write('<link rel="stylesheet" type="text/css" href="css/desktop/index.css">')
}