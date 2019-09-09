<html>
<head>
<script>
function startup() {
  var el = document.getElementsByTagName("canvas")[0];
  el.addEventListener("touchstart", handleStart, false);
  el.addEventListener("touchend", handleEnd, false);
  el.addEventListener("touchcancel", handleCancel, false);
  el.addEventListener("touchleave", handleEnd, false);
  el.addEventListener("touchmove", handleMove, false);
  log("initialized.");
  
  var ongoingTouches = new Array; 
  
  function handleStart(evt) {
  evt.preventDefault();
  log("touchstart.");
  var el = document.getElementsByTagName("canvas")[0];
  var ctx = el.getContext("2d");
  var touches = evt.changedTouches;
        
  for (var i=0; i < touches.length; i++) {
    log("touchstart:"+i+"...");
    ongoingTouches.push(copyTouch(touches[i]));
    var color = colorForTouch(touches[i]);
    ctx.beginPath();
    ctx.arc(touches[i].pageX, touches[i].pageY, 4, 0,2*Math.PI, false);  // a circle at the start
    ctx.fillStyle = color;
    ctx.fill();
    log("touchstart:"+i+".");
  }
}
}
</script>
</head>
<body>
	<canvas id="canvas" width="600" height="600" style="border:solid black 1px;">
	Seu browser não tem suporte ao elemento canvas.
	</canvas>
<br>
<button onclick="startup()">Initialize</button>
<br>
Log: <pre id="log" style="border: 1px solid #ccc;"></pre>

</body>
</html>