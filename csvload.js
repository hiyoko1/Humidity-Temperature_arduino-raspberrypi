﻿

// CSVファイル読み込み
function csvToArray(path) {
        var csvData = new Array();
        var data = new XMLHttpRequest();
        data.open("GET", path, false);
        data.send(null);
        var LF = String.fromCharCode(10);
        var lines = data.responseText.split(LF);
        for (var i = 0; i < lines.length;++i) {
                var cells = lines[i].split(",");
                if( cells.length != 1 ) {
                    csvData.push(cells);
                }
        }
        return csvData;
}

// ページロード時に実行
window.onload=function () {
    var data = csvToArray("data.csv");

    document.write('温度：',data[0][0],"<br>湿度：",data[0][1]);


};

