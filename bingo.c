/**
*** How to Program C
*** Test Week 3 - Bingo
**/
#include <stdio.h>

int main(void)
{
	int i, j, k;
	int l = 0;
	int check_col, check_row, check_diag_R, check_diag_L;
	int n, m; // n = number of gamers; m = matrix m * m
	int flag_win = 0;
	int flag_endgame = 0;
	int cnt_k = 0;
	int cnt_l = 0;
	int dia_cnt = 0;
	
	scanf("%d %d", &n, &m);
	// printf("%d %d\n", n, m);
	// printf("\n");
	
	int a[n][m][m];	// Bingo sheet of gamer n
	int b[m * m];	// numbers sheet of Bingo
	int g[n];		//Bingo result for each gamer, 100 means the first winner, others are 0.
	int win[10] = {-1}; 
	int lose[10] = {-1};
	
	for(i = 0; i < n; i ++)
	{
		g[i] = 0;
	}
	
	for(i = 0; i < n; i ++)
	{
		for(j = 0; j < m; j ++)
		{
			for(k = 0; k < m; k ++)
			{
				scanf("%d", &(a[i][j][k]));
			}
		}
	}
	
	/* Print the bingo sheet */
	// for(i = 0; i < n; i ++)
	// {
		// printf("Matrix %d is\n", i);
		// for(j = 0; j < m; j ++)
		// {	
			// for(k = 0; k < m; k ++)
			// {
				// printf("%4d ", a[i][j][k]);
			// }
			// printf("\n");
		// }
		// printf("\n");
	// }
	
	for(i = 0; i < m * m; i ++)
	{
		scanf("%d", &b[i]);
	}
	
	// printf("Bingo series is\n");
	// for(i = 0; i < m * m; i ++)
	// {
		// printf("%d ", b[i]);
	// }
	// printf("\n");
	
	for(l = 0; l < m * m && flag_endgame == 0; l ++)
	{
		printf("-------------Shout %d-------------\n", b[l]);
		for(i = 0; i < n; i ++)
		{
			for(j = 0; j < m; j ++)
			{
				for(k = 0; k < m; k ++)
				{
					if(a[i][j][k] == b[l])
					{
						a[i][j][k] = 0;
						
					}
				}
			}
		}
		
		/* Print the result of bingo sheet */
		// for(i = 0; i < n; i ++)
		// {
			// printf("Matrix %d is\n", i);
			// for(j = 0; j < m; j ++)
			// {	
				// for(k = 0; k < m; k ++)
				// {
					// printf("%4d ", a[i][j][k]);
				// }
				// printf("\n");
			// }
			// printf("\n");
		// }
		
		for(i = 0; i < n; i ++)
		{
			check_col = 0;
			check_row = 0;
			check_diag_R = 0;
			check_diag_L = 0;
			flag_win = 0;
			
			for(j = 0; j < m && flag_win == 0; j ++)
			{
				for(k = 0; k < m; k ++)
				{
					check_col += a[i][j][k];
					// printf("\n%d => (%d,%d)\n", i, j, k);
				}
				// printf("%d => check_col[%d] = %d\n", i, j, check_col);
				g[i] = (check_col == 0) ? 100 : 0;
				flag_win = (check_col == 0) ? 1 : 0;
				check_col = 0;
			}
			
			for(k = 0; k < m && flag_win == 0; k ++)
			{
				for(j = 0; j < m; j ++)
				{
					check_row += a[i][j][k];
					// printf("\n%d => (%d,%d)\n", i, j, k);
				}
				// printf("%d => check_row[%d] = %d\n", i, k, check_row);
				g[i] = (check_row == 0) ? 100 : 0;
				flag_win = (check_row == 0) ? 1 : 0;
				check_row = 0;
			}
			
			for(j = 0; j < m && flag_win == 0; j ++)
			{
				check_diag_R += a[i][j][j];
				// printf("\n%d => (%d,%d)\n", i, j, j);
			}
			// printf("%d => check_diag_R = %d\n", i, check_diag_R);
			g[i] = (check_diag_R == 0) ? 100 : 0;
			flag_win = (check_diag_R == 0) ? 1 : 0;
			// printf("g[%d] = %d\n",i , g[i]);
			
			
			for(j = m - 1; j >= 0 && flag_win == 0; j --)
			{	
				check_diag_L += a[i][dia_cnt][j];
				// printf("\n%d => (%d,%d)\n", i, dia_cnt, j);
				if(dia_cnt < m - 1)
				{
					dia_cnt ++;
				}	
			}
			dia_cnt = 0;
			// printf("%d => check_diag_L = %d\n", i, check_diag_L);
			g[i] = (check_diag_L == 0) ? 100 : 0;
			flag_win = (check_diag_L == 0) ? 1 : 0;
			// printf("g[%d] = %d\n",i , g[i]);
		}
		
		for(i = 0; i < n; i ++)
		{
			// printf("Check g[%d] = %d\n", i, g[i]);
			if(g[i] == 100)
			{
				flag_endgame = 1;
				printf("\n----------------------------------\n");
				// printf("g[%d] = %d, flag_endgame = %d.\n", i, g[i], flag_endgame);
				printf("Key number is ");
				printf("%d ", b[l]);
				printf(".\n");
				break;
			}
		}
	}
	
	for(i = 0; i < n; i ++)
	{
		if(g[i] == 100)
		{
			win[cnt_k] = i;
			cnt_k ++;
		}
		else
		{
			lose[cnt_l] = i;
			cnt_l ++;
		}
	}
	
	// printf("Winners are %d people; loasers are %d people.\n", cnt_k, cnt_l);
	
	/* Print the result of bingo sheet */
	// for(i = 0; i < n; i ++)
	// {
		// printf("Matrix %d is\n", i);
		// for(j = 0; j < m; j ++)
		// {	
			// for(k = 0; k < m; k ++)
			// {
				// printf("%4d ", a[i][j][k]);
			// }
			// printf("\n");
		// }
		// printf("\n");
	// }
	
	// printf("Game Result is\n");
	// for(i = 0; i < n; i ++)
	// {
		// printf("%d ", g[i]);
	// }
	// printf("\n");
	
	
	printf("Winners are\n");
	for(i = 0; i < cnt_k; i ++)
	{
		printf("%d ", win[i]);
	}
	printf("\n");
	
	printf("Losers are\n");
	for(i = 0; i < cnt_l; i ++)
	{
		printf("%d ", lose[i]);
	}
	printf("\n");

	getchar();
	getchar();
	return 0;
}