var MAP = {
	"20230000" : "load r1,0(r3)" ,
	"14210001" : "addi r1,r1,1" ,
	"24230000" : "store r1,0(r3)" ,
	"1c210080" : "subi r1,r1,128" ,
	"28000020" : "beq 8" ,
	"ffffffff" : "nop" ,
	"30000000" : "branch 0" ,
	"ffffffff" : "nop" ,
	"20230000" : "load r1,0(r3)" ,
	"20430000" : "load r2,0(r3)" ,
	"3c410002" : "srl r2,r2,1" ,
	"08210002" : "or r1,r1,r2" ,
	"24230000" : "store r1,0(r3)" 
};

function setOnBlock(id) {
    var r1 = document.getElementById(id);
    r1.style.display = "block"
}

function setOffBlock(id) {
    var r1 = document.getElementById(id);
    r1.style.display = "none"
}

var id;
var signal;
var color;

function display(x){
	$("#clk_num").html((x/2)+1);
	$("#up_down").html((x%2==0)?"上升沿":"下降沿");
	for (var key in signal[x]){
		var tmp = signal[x][key];
		if (MAP[tmp]!=null) tmp=MAP[tmp];
		if (key=="loaddepend") { tmp = (tmp=="0"?"1":"0"); }
		if ($("#"+key).html()!=tmp){
			$("#"+key).html(tmp);
		}

		if ($("."+key).html()!=tmp){
			$("."+key).css({
				color: 'red'	
			});
			$("."+key).html(tmp);
		}		
	}
}

function loadData() {
    $.getJSON('info.json', function(data) {
    	signal = data;
    	id = 0;
    	display(id);
    });
}

function nextHalfCyc()
{
	id++;
	if (id>signal.length)
		id--;	
	display(id);
}

function preHalfCyc()
{
	id--;
	if (id<0)
		id++;	
	display(id);
}

function nextCyc()
{
	id+=2;
	if (id>signal.length)
		id-=2;
	display(id);
}

function preCyc()
{
	id-=2;
	if (id<0)
		id+=2;
	display(id);
}