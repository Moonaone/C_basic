#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define K 5

float step1(float e_MEA, float e_EST)
{
	float K_k = e_EST / (e_EST + e_MEA);
	return K_k;
}

float step2(float X_hat, float K_k, float Z)
{
	float X_hat_k = X_hat + K_k * (Z - X_hat);
	return X_hat_k;
}

float step3(float K_k, float e_EST)
{
	float e_EST_k = (1 - K_k) * e_EST;
	return e_EST_k;
}

int main()
{
	int k = 1;
	float Z[K] = { 0 };
	float e_MEA =  0;
	float e_EST[K] = { 0 };
	float X_hat[K] = { 0 };
	float K_k[K] = { 0 };

	printf("X_hat_0 = ");
	scanf("%f", &X_hat[0]);
	printf("\ne_EST_0 = ");
	scanf("%f", &e_EST[0]);

	for(k = 1; k <= K; k++)
	{
		printf("\nZ [ %d ] = ", k);
		scanf("%f", &Z[k - 1 ]);
	}

	printf("\ne_MEA_1 = ");
	scanf("%f", &e_MEA);


	for (k = 1; k < K; k++)
	{
		K_k[k] = step1(e_MEA, e_EST[k - 1]);
		printf("\nK_k[ %d ] = %.3f", k, K_k[ k ]);
		X_hat[k] = step2(X_hat[k - 1], K_k[ k ], Z[ k - 1 ]);
		printf("\nX_hat[ %d ] = %.3f", k, X_hat[ k ]);
		e_EST[k] = step3(K_k[k], e_EST[k - 1]);
		printf("\ne_EST[ %d ] = %.3f", k, e_EST[ k ]);

		// Z_k为测量结果
		printf("\nZ[ %d ] = ", k + 1);
	}

	return 0;
}
