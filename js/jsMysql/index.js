
var pg = require('pg');
var connectionString = "postgres://userName:";

/*
var pgClient = new pg.Client(connectionString);

pgClient.connect();

var query = pgClient.query("SELECT id from Customer where name = 'customername'");


//Resultados

query.on("row", function(row,result){

result.addRow(row);

});


//Drop

query.on("end",function(result){
	if(result.rows[0] === undefined){
		return;
	}
	else{
	 	var id = result.row[0].id;

		var query = "delete from CustomerAddress where customer_id = " + id ;	
		pgClient.query(query);
	}
	pgClient.end();

});

*/

