#include <stdio.h>
#include <string.h>
#include <oqs/oqs.h>

// Define the message to be signed
#define MESSAGE (unsigned char *)"Hello, world!"
#define MESSAGE_LEN strlen((char *)MESSAGE)

/**
 * This program demonstrates the computation of a signature using the ML-DSA algorithm with Dilithium.
 * It generates a keypair, signs a message, and verifies the signature.
 */
int main()
{
    // Print test information
    printf("================================================================================\n");
    printf("               Sample computation for ML-DSA using Dilithium                    \n");
    printf("                      Algorithm: OQS_SIG_alg_dilithium_2                        \n");
    printf("--------------------------------------------------------------------------------\n");

    // Create a new signature object
    OQS_SIG *sig = OQS_SIG_new(OQS_SIG_alg_dilithium_2);
    // Check if the object was created successfully
    if (sig == NULL)
    {
        printf("Error al crear el contexto del algoritmo Dilithium\n");
        return EXIT_FAILURE;
    }

    // Generate a keypair
    uint8_t *public_key = malloc(sig->length_public_key);
    uint8_t *secret_key = malloc(sig->length_secret_key);
    // Check if the keypair was generated successfully
    if (OQS_SUCCESS != OQS_SIG_keypair(sig, public_key, secret_key))
    {
        printf("Error al generar el par de claves\n");
        return EXIT_FAILURE;
    }

    // Sign a message
    uint8_t *signature = malloc(sig->length_signature);
    size_t signature_len = sig->length_signature;
    // Check if the message was signed successfully
    if (OQS_SUCCESS != OQS_SIG_sign(sig, signature, &signature_len, MESSAGE, MESSAGE_LEN, secret_key))
    {
        printf("Error al firmar el mensaje\n");
        return EXIT_FAILURE;
    }

    // Print the results
    printf("                     Test result: ");

    // Verify the signature
    if (OQS_SUCCESS != OQS_SIG_verify(sig, MESSAGE, MESSAGE_LEN, signature, signature_len, public_key))
    {
        printf("signature is invalid (Error)\n");
        return EXIT_FAILURE;
    }

    // Print the results
    printf("La firma es válida (Success)\n");
    printf("================================================================================\n");

    // Free memory
    OQS_SIG_free(sig);
    free(public_key);
    free(secret_key);
    free(signature);

    return 0;
}