void generate_str(char* str)
{
	str[15] = 0;

	for(int i = 0; i < 15; i++) {
		str[i] = (rand() % 26) + 'a';
	}
}
