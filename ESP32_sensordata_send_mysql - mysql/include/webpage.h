//=====================
//HTML code for webpage
//=====================
const char webpageCont[] PROGMEM = 
R"=====(
<!DOCTYPE HTML>
<html>
<head>
  <title>ESP32 WebSocket Server</title>
  <link rel="stylesheet" href="ESP32_WS_BME280.css">
  <link rel="preconnect" href="https://fonts.gstatic.com">
  <link href="https://fonts.googleapis.com/css2?family=Caveat:wght@700&family=Kalam:wght@700&family=Shadows+Into+Light+Two&display=swap" rel="stylesheet">
  <link rel="preconnect" href="https://fonts.gstatic.com">
  <link href="https://fonts.googleapis.com/css2?family=Baloo+Tamma+2:wght@600&family=Caveat:wght@700&family=Kalam:wght@700&family=Shadows+Into+Light+Two&display=swap" rel="stylesheet">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
<style>
      html {
    font-family: Arial, Helvetica, sans-serif;
    text-align: center;
  }
      body
      {
        font-family: 'Baloo Tamma 2', cursive;
        background-color: rgba(0, 0, 0, 0.116);
      }
      h1
      {
        font-family: 'Shadows Into Light Two', cursive;
        color: crimson;
        font-size: 50px;
        margin-left: 20px;
      }
      h2
      {
        color: darkblue;
      }
      .title1
      {
        margin-left: 150px;
      }
      .BME
      {
        font-family: 'Baloo Tamma 2', cursive;
        background-color: gold;
        width: 110px;
        font-size: 20px;
        border: 2px solid black;
        margin-left: 150px;
      }
      .BMEo
      {
        font-family: 'Baloo Tamma 2', cursive;
        color:blue;
        background-color:blanchedalmond;
        width: 80px;
        font-size: 20px;
        text-align: center;
        border: 2px solid black;
      }
      .BMEo:hover
      {
        background-color: rgba(5, 0, 0, 0.144);
        transition: 0.5s;
      }
      .unt1
      {
        font-family: 'Baloo Tamma 2', cursive;
        color:blue;
      }
      .title2
     {
       margin-left: 150px;
     }
     .analog
     {
      font-family: 'Baloo Tamma 2', cursive;
      background-color: gold;
      width: 150px;
      font-size: 20px;
      border: 2px solid black;
      margin-bottom: 5px;
      margin-left: 150px;
     }
     .analogo
     {
      font-family: 'Baloo Tamma 2', cursive;
      color:blue;
      background-color:blanchedalmond;
      width: 80px;
      font-size: 20px;
      text-align: center;
      border: 2px solid black;
     }
     .analogo:hover
     {
      background-color: rgba(5, 0, 0, 0.144);
      transition: 0.5s;
     }
     .unt2
      {
        font-family: 'Baloo Tamma 2', cursive;
        color:blue;
      }
      .content {
    padding: 30px;
    max-width: 600px;
    margin: 0 auto;
  }
  .card {
    background-color: #F8F7F9;;
    box-shadow: 2px 2px 12px 1px rgba(140,140,140,.5);
    padding-top:10px;
    padding-bottom:20px;
  }
  .button {
    padding: 15px 50px;
    font-size: 24px;
    text-align: center;
    outline: none;
    color: #fff;
    background-color: #0f8b8d;
    border: none;
    border-radius: 5px;
    -webkit-touch-callout: none;
    -webkit-user-select: none;
    -khtml-user-select: none;
    -moz-user-select: none;
    -ms-user-select: none;
    user-select: none;
    -webkit-tap-highlight-color: rgba(0,0,0,0);
   }
   /*.button:hover {background-color: #0f8b8d}*/
   .button:active {
     background-color: #0f8b8d;
     box-shadow: 2 2px #CDCDCD;
     transform: translateY(2px);
   }
   .state {
     font-size: 1.5rem;
     color:#8c8c8c;
     font-weight: bold;
   }
</style>
<!----------------------H T M L------------------------>
</head>
<body>
    <h1>ESP32 WebSocket Server</h1>
    <h2>
      <p>
        <span class="title1">ESP32 Sensor data Measurements</span><br>
        <span class="BME">Temperature</span>
        <input class="BMEo" id="Temop">
        <span class="unt1"> C</span><br>
        <span class="BME">Humidity</span>
        <input class="BMEo" id="HUMop">
        <span class="unt1"> %</span><br>
        <span class="BME">CO2</span>
        <input class="BMEo" id="CO2op">
        <span class="unt1"> PPM</span><br>
        <span class="BME">CO</span>
        <input class="BMEo" id="COop">
        <span class="unt1"> PPM</span><br>
      </p>
    </h2>
    <div class="content">
      <div class="card">
        <h2>Output - GPIO 2</h2>
        <p class="state">state: <span id="state">%STATE%</span></p>
        <p><button id="button" class="button">Toggle</button></p>
      </div>
    </div>
    <script>
    </script>
  </body>
  </html>
)=====";
