

var myClosure = (function() { 
   	function _private_formatDoc(sCmd, sValue) {
	   document.execCommand(sCmd, false, sValue); document.getElementById("textBox").focus(); 
	}
    return {
        public_formatDoc: function(sCmd, sValue) {
            _private_formatDoc(sCmd,sValue);
        }
    };
}());

function crtFileFunc(contentG, fileNameG, idLst, contentLst){
		$.post('index.php', {content: contentG, fileName: fileNameG}, function(data){});	
		$(idLst).html(contentLst.concat('\r').concat('\n').concat(fileNameG));
};

function openFileFunc(fileNameG, id){		
	return new Promise(function (resolve, reject){
		var xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function() {
	    if (this.readyState === 4 && this.status === 200) {
	        myFunction(this);
	    }
	};

	xhttp.open('GET', 'files.xml', true);
	xhttp.send();

	xhttp.onerror = function() {
      reject(new Error("Network Error"));
    };

	function myFunction(xml) {
	    var xmlDoc = xml.responseXML;
	    var x = xmlDoc.getElementsByTagName("content")[0];
	    var y = x.nodeValue;
	   	$('#textBox').html(y);
	}
	});
}

