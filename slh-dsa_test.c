#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oqs/oqs.h>

// Define the message to be signed
#define MESSAGE (unsigned char *)"Hello, world!"
#define MESSAGE_LEN strlen((char *)MESSAGE)

/**
 * This program demonstrates the computation of a signature using the SLH-DSA algorithm with SPHINCS+.
 * It generates a keypair, signs a message, and verifies the signature.
 */
int main()
{
    // Print test information and algorithm name
    printf("================================================================================\n");
    printf("           Sample computation for signature SLH-DSA using SPHINICS+             \n");
    printf("              Algorithm: OQS_SIG_alg_sphincs_sha2_256s_simple                   \n");
    printf("--------------------------------------------------------------------------------\n");

    // Create a new signature object
    OQS_SIG *sig = OQS_SIG_new(OQS_SIG_alg_sphincs_sha2_256s_simple);
    // Check if the object was created successfully
    if (sig == NULL)
    {
        printf("OQS_SIG_new failed\n");
        return 1;
    }

    // Generate a keypair
    uint8_t *public_key = malloc(sig->length_public_key);
    uint8_t *secret_key = malloc(sig->length_secret_key);
    OQS_SIG_keypair(sig, public_key, secret_key);

    // Sign a message
    uint8_t *signature = malloc(sig->length_signature);
    size_t signature_len;
    OQS_SIG_sign(sig, signature, &signature_len, MESSAGE, MESSAGE_LEN, secret_key);

    // Print the results
    printf("                 Test result: ");

    // Verify the signature
    OQS_STATUS result = OQS_SIG_verify(sig, MESSAGE, MESSAGE_LEN, signature, signature_len, public_key);
    // Check if the signature is valid
    if (result == OQS_SUCCESS)
    {
        printf("Signature is valid! (Success)\n");
    }
    else
    {
        printf("Signature is invalid! (Error)\n");
    }
    printf("================================================================================\n");

    // Free memory
    OQS_SIG_free(sig);
    free(public_key);
    free(secret_key);
    free(signature);

    return 0;
}