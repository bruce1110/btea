#include "cjson/cJSON.h"
#include <stdio.h>

int main()
{

	char *my_json_string = "{\
		\n\"message\":\"json test\",\
		\n\"allRowCount\":2,\
	    \n\"root\":[{\
		\n    \"value\":\"2015-11-16 11:15\",\
		\n    \"id\":\"2015_20110.10000\",\
		\n    \"sex\":\"famale\"\
		\n }],\
		\n\"success\":\"true\"\
		\n}";
	cJSON * root = cJSON_Parse(my_json_string);
	char *rendered = cJSON_Print(root);
	printf("%s", rendered);
}
