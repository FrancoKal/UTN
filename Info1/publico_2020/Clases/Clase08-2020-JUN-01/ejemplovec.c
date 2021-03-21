
#define MAX_ALUMNOS 50


int notas[MAX_ALUMNOS];



....
....
....
....
....

for(i=0; (i<MAX_ALUMNOS) && (notas[i-1]>=0), i++)
{
	printf();
	scanf("%d", &notas[i]);
}


/* ESTO NO!!!!!!!!!!
for(i=0; i<MAX_ALUMNOS), i++)
{
	printf();
	scanf("%d", &notas[i]);

	if (notas[i]<0) break;
}

*/


i = 0;
while ((i<MAX_ALUMNOS) && (notas[i-1]>=0))
{
	printf();
	scanf("%d", &notas[i]);
	i++;
}


