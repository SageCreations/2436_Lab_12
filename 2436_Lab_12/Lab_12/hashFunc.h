int hashFunc(string name) {
	int i, sum;
	int len;
	i = 0; sum = 0;

	len = name.length();
	for (int k = 0; k < 15 - len; k++) {
		name = name + ' '; 		//increase the length of the name to 15 characters
  }

	for (int k = 0; k < 5; k++) {
		sum = sum + static_cast<int>(name[i]) * 128 * 128
		+ static_cast<int>(name[i + 1]) * 128
		+ static_cast<int>(name[i + 2]);
        i = i + 3;
	}
    return sum % HTSize;
}
