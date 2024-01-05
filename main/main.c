#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "tpm2_tss.h"
#include "tss2/tss2_sys.h"

#define LOGMODULE mainApp
#include "log.h"

#include "tcti-spi-esp32.h"

void tpm_startup(void){
	TSS2_TCTI_CONTEXT *tcti_ctx = NULL;
    TSS2_SYS_CONTEXT *sys_ctx = NULL;
    TSS2_RC rc;
    size_t size;
    TSS2_ABI_VERSION abi_version = {
        .tssCreator = 1,
        .tssFamily = 2,
        .tssLevel = 1,
        .tssVersion = 108,
    };

    size = Tss2_Sys_GetContextSize(0);
    sys_ctx = (TSS2_SYS_CONTEXT *) calloc(1, size);
    if (sys_ctx == NULL) {
        printf("Failed to allocate 0x%zx bytes for the SYS context\n", size);
        return;
    }

    tcti_ctx = create_tcti_ctx();
    if (tcti_ctx == NULL ) {
        printf("create_tcti_ctx failed\n");
        return;
    }

    rc = Tss2_Sys_Initialize(sys_ctx, size, tcti_ctx, &abi_version);
    if (rc != TSS2_RC_SUCCESS) {
    	printf("Failed to initialize SYS context: 0x%lx\n", rc);
        free(sys_ctx);
        return;
    }

    TSS2L_SYS_AUTH_RESPONSE rspAuthsArray;

    rc = Tss2_Sys_Startup( sys_ctx, TPM2_SU_CLEAR );
	if (rc != TSS2_RC_SUCCESS) {
		printf("Failed to Tss2_Sys_Startup : 0x%lx\n", rc);
		free(sys_ctx);
		return;
	}else{
		printf("Tss2_Sys_Startup success \n");
	}

	rc = Tss2_Sys_SelfTest(sys_ctx, NULL, TPM2_YES, &rspAuthsArray);
	if(rc != TSS2_RC_SUCCESS){
		printf("Failed to Tss2_Sys_SelfTest \n");
	} else {
		printf("Tss2_Sys_SelfTest success \n");
	}

//    rc = Tss2_Sys_Clear(sys_ctx);
//    if (rc != TSS2_RC_SUCCESS) {
//        printf("Tss2_Sys_Clear failed: 0x%x\n", rc);
//    }

    printf("Tast_ finished...\n");

}

void tesk_loop(){
	tpm_startup();

    while (true) {
        printf("Hello from app_main!\n");
        sleep(1);
    }
    vTaskDelay(NULL);
}

void app_main(void)
{
	xTaskCreate(tesk_loop, "", 1024*8, NULL, 10, NULL);

    /*while (true) {
        printf("Hello from app_main!\n");
        sleep(1);
    }*/
}
