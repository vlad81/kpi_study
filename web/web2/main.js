

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
