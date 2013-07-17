/*
 *********************************************
 *  314 Principles of Programming Languages  *
 *  Spring 2013                              *
 *  Authors: Ulrich Kremer                   *
 *           Hans Christian Woithe           *
 *********************************************
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "InstrUtils.h"
#include "Utils.h"

int main()
{
	Instruction *head;
	Instruction *instr1, *instr2, *instr3;
	int x, y, z, count = 0;

	head = ReadInstructionList(stdin);
	instr1 = head;
	if (!head) 
	{
		ERROR("No instructions\n");
		exit(EXIT_FAILURE);
	}
	while(count != 5)
	{
		if(instr1 -> opcode == LOADI)
		{
			x = instr1->field2;
			instr2 = instr1 -> next;
			if(instr2->opcode == LOADI)
			{
				y = instr2->field2;
				instr3 = instr2 -> next;
				if(instr3->opcode == ADD)
				{
					z = x+y;
					instr1->field1 = instr3->field1;
					instr1->field2 = z;
					instr1->next = instr3->next;
					free(instr2);
					free(instr3);
				}
				else if(instr3->opcode == SUB)
				{
					z = x-y;
					instr1->field1 = instr3->field1;
					instr1->field2 = z;
					instr1->next = instr3->next;
					free(instr2);
					free(instr3);
				}
				else if(instr3->opcode == MUL)
				{
					z = x*y;
					instr1->field1 = instr3->field1;
					instr1->field2 = z;
					instr1->next = instr3->next;
					free(instr2);
					free(instr3);
				}
			}
		}
		instr1 = instr1->next;
		if(instr1 == NULL)
		{
			instr1 = head;
			count++;
		}
	}
	PrintInstructionList(stdout, head);
	DestroyInstructionList(head);
	return EXIT_SUCCESS;
}
