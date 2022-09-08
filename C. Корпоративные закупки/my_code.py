import datetime, json

# input
products_in_JSON  = input()
list_JSON = json.loads(products_in_JSON)

statements = [input() for i in range(5)]

# solution
statements = [{"state": statement.split()[0], "value" : (int(statement.split()[1])
														 if ('PRICE' in statement.split()[0])
														 else statement.split()[1])} for statement in statements]

def comp_Date(x, y) :
	return datetime.datetime.strptime(x, '%d.%m.%Y') >= datetime.datetime.strptime(y, '%d.%m.%Y')

for statement in statements:
	if statement['state'] == 'PRICE_LESS_THAN' :
		list_JSON = [el for el in list_JSON if el['price'] <= statement['value']]
	if statement['state'] == 'DATE_AFTER' :
		list_JSON = [el for el in list_JSON if comp_Date(el['date'], statement['value'])]
	if statement['state'] == 'NAME_CONTAINS' :
		list_JSON = [el for el in list_JSON if statement['value'].upper() in el['name'].upper()]
	if statement['state'] == 'PRICE_GREATER_THAN' :
		list_JSON = [el for el in list_JSON if el['price'] >= statement['value']]
	if statement['state'] == 'DATE_BEFORE' :
		list_JSON = [el for el in list_JSON if not comp_Date(el['date'], statement['value']) or el['date'] == statement['value']]

# output
list_JSON.sort(key = lambda x : int(x['id']))
print(json.dumps(list_JSON))
