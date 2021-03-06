//   3DS.js
//   © 2015-Present filfat Studios AB
//   Please see the LICENSE for more info!
#include <3ds.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "duktape/duktape.h"

using namespace std;


duk_function_list_entry input_funcs[] = {
	{ "getInputDown", input_getInputDown, 3 },
	{ "getInputUp", input_getInputUp, 2 },
	{ "getInput", input_getInput, 1 },
	{ NULL, NULL, 0 }
};

int input_getInputDown(duk_context *ctx) {
	hidScanInput();
	touchPosition tp;
	u32 k = hidKeysDown();
	hidTouchRead(&tp);
	
	duk_idx_t obj = duk_push_object(ctx);
	
	duk_push_boolean(ctx, (k));
	duk_put_prop_string(ctx, obj, "KEY");
	
	duk_push_boolean(ctx, (k & KEY_A));
	duk_put_prop_string(ctx, obj, "KEY_A");
	duk_push_boolean(ctx, (k & KEY_B));
	duk_put_prop_string(ctx, obj, "KEY_B");
	duk_push_boolean(ctx, (k & KEY_X));
	duk_put_prop_string(ctx, obj, "KEY_X");
	duk_push_boolean(ctx, (k & KEY_Y));
	duk_put_prop_string(ctx, obj, "KEY_Y");
	
	duk_push_boolean(ctx, (k & KEY_UP));
	duk_put_prop_string(ctx, obj, "KEY_UP");
	duk_push_boolean(ctx, (k & KEY_RIGHT));
	duk_put_prop_string(ctx, obj, "KEY_RIGHT");
	duk_push_boolean(ctx, (k & KEY_DOWN));
	duk_put_prop_string(ctx, obj, "KEY_DOWN");
	duk_push_boolean(ctx, (k & KEY_LEFT));
	duk_put_prop_string(ctx, obj, "KEY_LEFT");
	
	duk_push_boolean(ctx, (k & KEY_START));
	duk_put_prop_string(ctx, obj, "KEY_START");
	duk_push_boolean(ctx, (k & KEY_SELECT));
	duk_put_prop_string(ctx, obj, "KEY_SELECT");
	
	duk_push_boolean(ctx, (k & KEY_L));
	duk_put_prop_string(ctx, obj, "KEY_L");
	duk_push_boolean(ctx, (k & KEY_R));
	duk_put_prop_string(ctx, obj, "KEY_R");
	
	duk_push_boolean(ctx, (k & KEY_TOUCH));
	duk_put_prop_string(ctx, obj, "KEY_TOUCH");
	duk_push_number(ctx, (int)tp.px);
	duk_put_prop_string(ctx, obj, "TOUCH_X");
	duk_push_number(ctx, (int)tp.py);
	duk_put_prop_string(ctx, obj, "TOUCH_Y");
	
	return 1;
}

int input_getInputUp(duk_context *ctx) {
	hidScanInput();
	touchPosition tp;
	u32 k = hidKeysUp();
	hidTouchRead(&tp);
	
	duk_idx_t obj = duk_push_object(ctx);
	
	duk_push_boolean(ctx, (k));
	duk_put_prop_string(ctx, obj, "KEY");
	
	duk_push_boolean(ctx, (k & KEY_A));
	duk_put_prop_string(ctx, obj, "KEY_A");
	duk_push_boolean(ctx, (k & KEY_B));
	duk_put_prop_string(ctx, obj, "KEY_B");
	duk_push_boolean(ctx, (k & KEY_X));
	duk_put_prop_string(ctx, obj, "KEY_X");
	duk_push_boolean(ctx, (k & KEY_Y));
	duk_put_prop_string(ctx, obj, "KEY_Y");
	
	duk_push_boolean(ctx, (k & KEY_UP));
	duk_put_prop_string(ctx, obj, "KEY_UP");
	duk_push_boolean(ctx, (k & KEY_RIGHT));
	duk_put_prop_string(ctx, obj, "KEY_RIGHT");
	duk_push_boolean(ctx, (k & KEY_DOWN));
	duk_put_prop_string(ctx, obj, "KEY_DOWN");
	duk_push_boolean(ctx, (k & KEY_LEFT));
	duk_put_prop_string(ctx, obj, "KEY_LEFT");
	
	duk_push_boolean(ctx, (k & KEY_START));
	duk_put_prop_string(ctx, obj, "KEY_START");
	duk_push_boolean(ctx, (k & KEY_SELECT));
	duk_put_prop_string(ctx, obj, "KEY_SELECT");
	
	duk_push_boolean(ctx, (k & KEY_L));
	duk_put_prop_string(ctx, obj, "KEY_L");
	duk_push_boolean(ctx, (k & KEY_R));
	duk_put_prop_string(ctx, obj, "KEY_R");
	
	duk_push_boolean(ctx, (k & KEY_TOUCH));
	duk_put_prop_string(ctx, obj, "KEY_TOUCH");
	duk_push_number(ctx, (int)tp.px);
	duk_put_prop_string(ctx, obj, "TOUCH_X");
	duk_push_number(ctx, (int)tp.py);
	duk_put_prop_string(ctx, obj, "TOUCH_Y");
	
	return 1;
}

int input_getInput(duk_context *ctx) {
	hidScanInput();
	touchPosition tp;
	u32 k = hidKeysHeld();
	hidTouchRead(&tp);
	
	duk_idx_t obj = duk_push_object(ctx);
	
	duk_push_boolean(ctx, (k));
	duk_put_prop_string(ctx, obj, "KEY");
	
	duk_push_boolean(ctx, (k & KEY_A));
	duk_put_prop_string(ctx, obj, "KEY_A");
	duk_push_boolean(ctx, (k & KEY_B));
	duk_put_prop_string(ctx, obj, "KEY_B");
	duk_push_boolean(ctx, (k & KEY_X));
	duk_put_prop_string(ctx, obj, "KEY_X");
	duk_push_boolean(ctx, (k & KEY_Y));
	duk_put_prop_string(ctx, obj, "KEY_Y");
	
	duk_push_boolean(ctx, (k & KEY_UP));
	duk_put_prop_string(ctx, obj, "KEY_UP");
	duk_push_boolean(ctx, (k & KEY_RIGHT));
	duk_put_prop_string(ctx, obj, "KEY_RIGHT");
	duk_push_boolean(ctx, (k & KEY_DOWN));
	duk_put_prop_string(ctx, obj, "KEY_DOWN");
	duk_push_boolean(ctx, (k & KEY_LEFT));
	duk_put_prop_string(ctx, obj, "KEY_LEFT");
	
	duk_push_boolean(ctx, (k & KEY_START));
	duk_put_prop_string(ctx, obj, "KEY_START");
	duk_push_boolean(ctx, (k & KEY_SELECT));
	duk_put_prop_string(ctx, obj, "KEY_SELECT");
	
	duk_push_boolean(ctx, (k & KEY_L));
	duk_put_prop_string(ctx, obj, "KEY_L");
	duk_push_boolean(ctx, (k & KEY_R));
	duk_put_prop_string(ctx, obj, "KEY_R");
	
	duk_push_boolean(ctx, (k & KEY_TOUCH));
	duk_put_prop_string(ctx, obj, "KEY_TOUCH");
	duk_push_number(ctx, (int)tp.px);
	duk_put_prop_string(ctx, obj, "TOUCH_X");
	duk_push_number(ctx, (int)tp.py);
	duk_put_prop_string(ctx, obj, "TOUCH_Y");
	
	return 1;
}

void inputInit(duk_context *ctx) {
	duk_push_global_object(ctx);
	duk_push_object(ctx);
	duk_put_function_list(ctx, -1, input_funcs);
	duk_put_prop_string(ctx, -2, "Input");
	duk_pop(ctx);
	
	log("[Init] inputInit: Done!");
}