String AJAXmodule = R"=====( 
<script>
  var ajaxRequest = null;
  if(window.XMLHttpRequest){
    ajaxRequest =new XMLHttpRequest();
  }
  function ajaxLoad(ajaxURL){
    ajaxRequest.open("GET",ajaxURL,true);
    ajaxRequest.onreadystatechange = function(){
      if(ajaxRequest.readyState == 4 && ajaxRequest.status==200){
        var ajaxResult = ajaxRequest.responseText;
////////////

////////////
      }
    }
    ajaxRequest.send();
  }

</script>
)=====";
String FEEDBACKmodule = R"=====( 
<script type='text/javascript'>

function changeColor(){
let red= document.getElementById('sliderVal1').value; var Ared= 180-red;
let green= document.getElementById('sliderVal2').value; var Agreen= 180-green;
let blue= document.getElementById('sliderVal3').value; var Ablue= 180-blue;
let color= 'rgb(' + red*255/180 + ',' + green*255/180 + ',' + blue*255/180 + ')';
let Acolor= 'rgb(' + Ared*255/180 + ',' + Agreen*255/180 + ',' + Ablue*255/180 + ')';
document.body.style.backgroundColor = color; document.body.style.color = Acolor;}
document.getElementById('sliderVal1').addEventListener('input',changeColor);
document.getElementById('sliderVal2').addEventListener('input',changeColor);
document.getElementById('sliderVal3').addEventListener('input',changeColor);
document.getElementById('sliderVal1').addEventListener('input',trigger);
document.getElementById('sliderVal2').addEventListener('input',trigger);
document.getElementById('sliderVal3').addEventListener('input',trigger);
var state=0;
function trigger(){
  clearTimeout(triggertime);
   clearTimeout(timeout);
 state=1;
var triggertime = setTimeout(function(){state=0;},20);
var timeout = setTimeout(feedback,200);
  }
  function loop(){
    if(state==1){
      feedback();
      }
    setTimeout(loop,20);
    }
function feedback(){
let val1= document.getElementById('sliderVal1').value;
let val2= document.getElementById('sliderVal2').value;
let val3= document.getElementById('sliderVal3').value;
  ajaxLoad('val1=' + val1 + '&' + 'val2=' + val2 + '&' + 'val3=' + val3 + '&');
}
</script>
)=====";
void controlHTML(){
 

    client.println("<!DOCTYPE html><html>");
    client.println("<head><meta charset=\"utf-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");  //utf-8 related to emoji
    client.println("<link rel=\"icon\" href=\"data:,\">");
    client.println("<style> img {display: block; margin-left: auto; margin-right: auto; } html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
    client.println("button.SBUTT{width:80px; height:40px;} input.CFCBOX{width:40px; height:40px;} .slider{ width:80%;}</style><title>&#x1F602&#x1F602&#x1F602</title></head>"); //&#x1f602=U+1F602
    client.println(AJAXmodule);
    client.println("<body onload='loop()'>");
            client.println("<h1><span id='instaV1W' style='color:white'></span>  <span id='instaVal1'></span>  <span id='instaV1B' style='color:black'></span></h1>");////
            client.println("<input type='range' min='0' max='180' class='slider' id='sliderVal1' onchange='feedback()' value='"+valueString1+"'/>");
            client.println("<script>var sliderV1 = document.getElementById('sliderVal1');");
            client.println("instaVal1.innerHTML = sliderV1.value;");
            client.println("sliderV1.oninput = function() {instaV1W.innerHTML = this.value; instaV1B.innerHTML = this.value; instaVal1.innerHTML = this.value;}</script>");

            client.println("<h1><span id='instaV2W'style='color:white'></span>  <span id='instaVal2'></span>  <span id='instaV2B' style='color:black'></span></h1>");////
            client.println("<input type='range' min='0' max='180' class='slider' id='sliderVal2' onchange='feedback()' value='"+valueString2+"'/>");
            client.println("<script>var sliderV2 = document.getElementById('sliderVal2');");
            client.println("instaVal2.innerHTML = sliderV2.value;");
            client.println("sliderV2.oninput = function() {instaV2W.innerHTML = this.value; instaV2B.innerHTML = this.value; instaVal2.innerHTML = this.value;}</script>");

            client.println("<h1><span id='instaV3W' style='color:white'></span>  <span id='instaVal3'></span>  <span id='instaV3B' style='color:black'></span></h1>");////
            client.println("<input type='range' min='0' max='180' class='slider' id='sliderVal3' onchange='feedback()' value='"+valueString3+"'/>");
            client.println("<script>var sliderV3 = document.getElementById('sliderVal3');");
            client.println("instaVal3.innerHTML = sliderV3.value;");
            client.println("sliderV3.oninput = function() {instaV3W.innerHTML = this.value; instaV3B.innerHTML = this.value; instaVal3.innerHTML = this.value;}</script>");

    client.println("<form method=GET><button type='submit' class='SBUTT'>SUBMIT</button>")  ;
    client.println("<br><div><h1>TO CONFIG</h1><input type='checkbox' class='CFCBOX' name='configMode'></input></div>");
    client.println(FEEDBACKmodule);
    client.println("</form></body></html>");
 
}
