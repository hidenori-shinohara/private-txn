#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "circom.hpp"
#include "calcwit.hpp"
void PrivateTxn_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void PrivateTxn_0_run(uint ctx_index,Circom_CalcWit* ctx);
void commit_0(Circom_CalcWit* ctx,FrElement* lvar,uint componentFather,FrElement* destination,int destination_size);
Circom_TemplateFunction _functionTable[1] = { 
PrivateTxn_0_run };
Circom_TemplateFunction _functionTableParallel[1] = { 
NULL };
uint get_main_input_signal_start() {return 4;}

uint get_main_input_signal_no() {return 7;}

uint get_total_signal_no() {return 13;}

uint get_number_of_components() {return 1;}

uint get_size_of_input_hashmap() {return 256;}

uint get_size_of_witness() {return 6;}

uint get_size_of_constants() {return 2;}

uint get_size_of_io_map() {return 0;}

void release_memory_component(Circom_CalcWit* ctx, uint pos) {{

if (pos != 0){{

delete ctx->componentMemory[pos].subcomponents;

delete ctx->componentMemory[pos].subcomponentsParallel;

delete ctx->componentMemory[pos].outputIsSet;

delete ctx->componentMemory[pos].mutexes;

delete ctx->componentMemory[pos].cvs;

delete ctx->componentMemory[pos].sbct;

}}


}}


// function declarations
void commit_0(Circom_CalcWit* ctx,FrElement* lvar,uint componentFather,FrElement* destination,int destination_size){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement expaux[4];
std::string myTemplateName = "commit";
u64 myId = componentFather;
// return bucket
Fr_mul(&expaux[1],&circuitConstants[1],&lvar[0]); // line circom 9
Fr_add(&expaux[0],&expaux[1],&lvar[1]); // line circom 9
Fr_copy(destination,&expaux[0]);
return;
}

// template declarations
void PrivateTxn_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 0;
ctx->componentMemory[coffset].templateName = "PrivateTxn";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 7;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void PrivateTxn_0_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* signalValues = ctx->signalValues;
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
FrElement* circuitConstants = ctx->circuitConstants;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
FrElement expaux[6];
FrElement lvar[0];
uint sub_component_aux;
uint index_multiple_eq;
{

// start of call bucket
FrElement lvarcall[2];
// copying argument 0
Fr_copy(&lvarcall[0],&signalValues[mySignalStart + 3]);
// end copying argument 0
// copying argument 1
Fr_copy(&lvarcall[1],&signalValues[mySignalStart + 4]);
// end copying argument 1
commit_0(ctx,lvarcall,myId,&signalValues[mySignalStart + 0],1);
// end call bucket
}

{

// start of call bucket
FrElement lvarcall[2];
// copying argument 0
Fr_copy(&lvarcall[0],&signalValues[mySignalStart + 5]);
// end copying argument 0
// copying argument 1
Fr_copy(&lvarcall[1],&signalValues[mySignalStart + 6]);
// end copying argument 1
commit_0(ctx,lvarcall,myId,&signalValues[mySignalStart + 1],1);
// end call bucket
}

{

// start of call bucket
FrElement lvarcall[2];
// copying argument 0
Fr_copy(&lvarcall[0],&signalValues[mySignalStart + 7]);
// end copying argument 0
// copying argument 1
Fr_copy(&lvarcall[1],&signalValues[mySignalStart + 8]);
// end copying argument 1
commit_0(ctx,lvarcall,myId,&signalValues[mySignalStart + 2],1);
// end call bucket
}

Fr_add(&expaux[3],&signalValues[mySignalStart + 5],&signalValues[mySignalStart + 7]); // line circom 35
Fr_add(&expaux[2],&expaux[3],&signalValues[mySignalStart + 9]); // line circom 35
Fr_eq(&expaux[0],&signalValues[mySignalStart + 3],&expaux[2]); // line circom 35
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 35. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
Fr_geq(&expaux[0],&signalValues[mySignalStart + 5],&circuitConstants[0]); // line circom 40
if(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + 10];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
}else{
{
PFrElement aux_dest = &signalValues[mySignalStart + 10];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
}
Fr_geq(&expaux[0],&signalValues[mySignalStart + 7],&circuitConstants[0]); // line circom 42
if(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &signalValues[mySignalStart + 11];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[1]);
}
}else{
{
PFrElement aux_dest = &signalValues[mySignalStart + 11];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
}
Fr_mul(&expaux[1],&signalValues[mySignalStart + 10],&signalValues[mySignalStart + 11]); // line circom 43
Fr_eq(&expaux[0],&expaux[1],&circuitConstants[1]); // line circom 43
if (!Fr_isTrue(&expaux[0])) std::cout << "Failed assert in template/function " << myTemplateName << " line 43. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(&expaux[0]));
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0)release_memory_component(ctx,index_subc);
}
}

void run(Circom_CalcWit* ctx){
PrivateTxn_0_create(1,0,ctx,"main",0);
PrivateTxn_0_run(0,ctx);
}

