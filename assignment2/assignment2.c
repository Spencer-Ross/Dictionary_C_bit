/***********************************************************************
name: SPENCER ROSS
	ok -- see if a word is in the online dictionary
description:
	Returns line number if the word exists in the dictionary, otherwise
	returns negative of the line number	
	See CS 360 IO lecture for details.
***********************************************************************/

/* Includes and definitions */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>


/**********************************************************************
Search for given word in dictionary using file descriptor fd.
Return line number if word found, else negative line number.
**********************************************************************/

/*Calculates the number of lines in the dictionary*/
long getF_height(long size, int dictWidth) {
	return (size / dictWidth);
}


/*compares two strings and returns:
**					0 if word == check
**					1 if word < check
**					-1 if check < word
*/
int myStringComp(char* word, char* check, int length) {
	for(int i = 0; i < length; i++) {
		if(word[i] != check[i]) {
			if(word[i] < check[i])
				return -1;
			return 1;
		}
	}

	return 0;
}


/* truncates or formats incoming word to length of dictionary*/
char* format(char* word, int length) {
	char* newWord = malloc(sizeof(char));
	int count = 0, i;

	for(i = 0; i < length && word[i] != '\0'; i++) {
		newWord[i] = word[i];
	}

	while(i < length) {
		newWord[i++] = ' ';
	}

	newWord[--i] = '\n';
	newWord[++i] = '\0';

	return newWord;
}


int ok(char *dictionaryName, char *word, int dictWidth) {
	int i, retVal, position, compResult, floor = 1;

	int fd = open(dictionaryName, O_RDONLY);
	if(fd < 0) return (errno);
	
	int size = lseek(fd, 0, SEEK_END);
	if(size < 0) return(errno);
	int height = getF_height(size, dictWidth); //get height aka num of lines
	
	char check[dictWidth];
	word = format(word, dictWidth);

	//read input from dictionary
	position = ((height + floor) / 2);
	lseek(fd, ((position-1) * dictWidth), SEEK_SET);	//go to line in the middle

	while((floor <= height)) {
		if(read(fd, check, dictWidth) < 0) 
			return (errno);

		check[dictWidth] = '\0';
		lseek(fd, -dictWidth, SEEK_CUR);
		compResult = myStringComp(word, check, dictWidth);

		if(compResult == 0)
			return position;
		else if(compResult < 0) {
			if(floor == (height - 1))
				return -position;
			height = position - 1;
		}
		else
			floor = position + 1;

		position = ((height + floor) / 2);
		position = (position > 0) ? position : 1;
		lseek(fd, ((position-1) * dictWidth), SEEK_SET); //go to new middle
	}
	
	free(word);
	close(fd);
	return -position;
}

