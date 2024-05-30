#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oqs/oqs.h>

/**
 * This program demonstrates the computation of a shared secret using the ML-KEM algorithm with Kyber-768.
 * It generates a keypair, encapsulates a shared secret, and decapsulates the shared secret.
 */
int main()
{
    // Print test information
    printf("================================================================================\n");
    printf("               Sample computation for ML-KEM using Kyber-768                    \n");
    printf("                      Algorithm: OQS_KEM_alg_kyber_768                          \n");
    printf("--------------------------------------------------------------------------------\n");
    OQS_KEM *kem = NULL;
    kem = OQS_KEM_new(OQS_KEM_alg_kyber_768);
    if (kem == NULL)
    {
        printf("Error: OQS_KEM_new failed\n");
        return EXIT_FAILURE;
    }

    // Declare variables
    uint8_t *public_key = NULL;
    uint8_t *secret_key = NULL;
    uint8_t *ciphertext = NULL;
    uint8_t *shared_secret_e = NULL;
    uint8_t *shared_secret_d = NULL;

    // Allocate memory
    public_key = malloc(kem->length_public_key);
    secret_key = malloc(kem->length_secret_key);
    ciphertext = malloc(kem->length_ciphertext);
    shared_secret_e = malloc(kem->length_shared_secret);
    shared_secret_d = malloc(kem->length_shared_secret);

    // Generate a keypair
    if (OQS_KEM_keypair(kem, public_key, secret_key) != OQS_SUCCESS)
    {
        printf("Error al generar el par de claves\n");
        return EXIT_FAILURE;
    }

    // Encapsulate
    if (OQS_KEM_encaps(kem, ciphertext, shared_secret_e, public_key) != OQS_SUCCESS)
    {
        printf("Error al encapsular\n");
        return EXIT_FAILURE;
    }

    // Decapsulate
    if (OQS_KEM_decaps(kem, shared_secret_d, ciphertext, secret_key) != OQS_SUCCESS)
    {
        printf("Error al desencapsular\n");
        return EXIT_FAILURE;
    }

    // Print the results
    printf("                     Test result: ");

    // Check if the shared secrets match
    if (memcmp(shared_secret_e, shared_secret_d, kem->length_shared_secret) != 0)
    {
        printf("shared secrets do not match (Error)\n");
        return EXIT_FAILURE;
    }

    // Notify the user that the shared secrets match
    printf("shared secrets match (Success)\n");
    printf("================================================================================\n");

    // Free memory
    OQS_KEM_free(kem);
    free(public_key);
    free(secret_key);
    free(ciphertext);
    free(shared_secret_e);
    free(shared_secret_d);

    return EXIT_SUCCESS;
}