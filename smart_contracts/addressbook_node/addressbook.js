const Eos = require('eosjs');
const ADDRESS_BOOK = 'addressbook';
const HELLO = 'hello';
const ALICE = 'alice';

let eos = Eos({
	keyProvider: '5KcfzeNnVdw5ikerdQSajCgpXqWWjQVMJx7LfZVpgBVPznKqk7f'
})


//you can run the exact same queries found in the HTTP API documentation
//eos.getBlock(1).then((err, res) => {
//	if(err) console.log(err);
//	if(res) console.log(res);
//});

let options = {
  authorization: ALICE+'@active',
  broadcast: true,
  sign: true
}

//eos.contract(HELLO).then(helloContract => {
//	//we use options here to sign the transaction with alices active key
//	helloContract.hi(ALICE, options).then(response => {
//		console.log(response)
//		const actions = response.transaction.transaction.actions;
//	})
//})


//eos.contract(ADDRESS_BOOK).then(addressBookContract => {
//	const user = {
//		account: ALICE,
//		first_name: 'alice',
//		last_name: 'in wonderland',
//		street: 'foo',
//		city: 'bar',
//		state: 'Wonderlandville',
//		zip: 98109
//	}
//	addressBookContract.add(user, options).then(response => {
//		console.log(response)
//		const actions = response.transaction.transaction.actions;
//	})
//})
//


//here we can query the database just like the cleos get table command
//eos.getTableRows({json:true, scope: ADDRESS_BOOK, code: ADDRESS_BOOK, table: "address"})
//.then(res => {
//	console.log(res.rows.length) 
//	let row = res.rows[0]; 
//	console.log(row); 
//});

//we can also run the same find queries as before, here we're querying for Alice, and only returning her address book data.
eos.getTableRows({json:true, scope: ADDRESS_BOOK, code: ADDRESS_BOOK, table: "address", limit:1, lower_bound: ALICE, upper_bound:'alice'+1})
.then(res => {
	console.log(res.rows.length) 
	let row = res.rows[0]; 
	console.log(row); 
});
