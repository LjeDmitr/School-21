static char *OPN(char *str)
{
	char stack[100];
	char *output = calloc(sizeof(char), 100);
	int indexOut = 0, indexStack = 0;
	for (int i = 0; str[i] != '\r' && str[i] != '\n'; i++)
	{
		if (isupper(str[i]) != 0 || isdigit(str[i]))
		{
			output[indexOut] = str[i];
			indexOut++;
		}
		else if (str[i] == '(')
		{
			stack[indexStack] = str[i];
			indexStack++;
		}
		else if (str[i] == ')')
		{
			for (; indexStack >= 0 && stack[indexStack - 1] != '('; indexStack--, indexOut++)
			{
				output[indexOut] = stack[indexStack - 1];
			}
			if (indexStack < 0)
			{
				return NULL;
			}
			if (indexStack != 0)
			{
				indexStack--;
			}
		}
		else if (str[i] == '+')
		{
			for (; indexStack >= 0 && (stack[indexStack - 1] == '+' || stack[indexStack - 1] == '-' || stack[indexStack - 1] == '*' || stack[indexStack - 1] == '/'); indexStack--, indexOut++)
			{
				output[indexOut] = stack[indexStack - 1];
			}
			stack[indexStack] = str[i];
			indexStack++;
		}
		else if (str[i] == '-')
		{
			for (; indexStack >= 0 && (stack[indexStack - 1] == '+' || stack[indexStack - 1] == '-' || stack[indexStack - 1] == '*' || stack[indexStack - 1] == '/'); indexStack--, indexOut++)
			{
				output[indexOut] = stack[indexStack - 1];
			}
			stack[indexStack] = str[i];
			indexStack++;
		}
		else if (str[i] == '*')
		{
			for (; indexStack >= 0 && (stack[indexStack - 1] == '*' || stack[indexStack - 1] == '/'); indexStack--, indexOut++)
			{
				output[indexOut] = stack[indexStack - 1];
			}
			stack[indexStack] = str[i];
			indexStack++;
		}
		else if (str[i] == '/')
		{
			for (; indexStack >= 0 && (stack[indexStack - 1] == '/' || stack[indexStack - 1] == '*'); indexStack--, indexOut++)
			{
				output[indexOut] = stack[indexStack - 1];
			}
			stack[indexStack] = str[i];
			indexStack++;
		}
	}
	for (indexStack--; indexStack >= 0; indexStack--)
	{
		if (stack[indexStack] == '(' || stack[indexStack] == ')')
		{
			printf("Invalid format for writing an arithmetic expression\n");
			exit(-1);
		}
		output[indexOut] = stack[indexStack];
		indexOut++;
	}
	return output;
}
