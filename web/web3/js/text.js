var getText = (function(id) {
	function private_getText(id_1) {
		element = document.getElementById(id_1);
		var searchThis = element.textContent || element.innerHTML;
		//alert(searchThis);
		return searchThis;
	}
	return {
		public_get_Text: function(id) {
			return private_getText(id);
		} 
	}
}());