#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/TextDiagnosticPrinter.h>
#include <clang/Driver/Driver.h>
#include <clang/Frontend/FrontendAction.h>
#include <clang/Frontend/CompilerInvocation.h>
#include <clang/Frontend/FrontendActions.h>  
#include <clang/FrontendTool/Utils.h>            
#include <llvm/TargetParser/Host.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/TargetSelect.h>       
#include <lld/Common/CommonLinkerContext.h>       
#include <lld/Common/Driver.h>

using namespace clang;
using namespace llvm;
using namespace lld;
LLD_HAS_DRIVER(elf)

int main() {
    auto diagOpts = new DiagnosticOptions();
    auto *diagClient = new TextDiagnosticPrinter(llvm::errs(), diagOpts);
    IntrusiveRefCntPtr<DiagnosticIDs> diagID(new DiagnosticIDs());
    DiagnosticsEngine diags(diagID, diagOpts, diagClient);
    std::unique_ptr<CompilerInstance> Clang(new CompilerInstance());
    // HIP
    std::vector<const char*> args = {
        "clang",
        "-x", "hip",
        "-nogpulib",
        "-triple", "amdgcn-amd-amdhsa",
        "-target-cpu", "gfx1100",
        "-target-feature", "+wavefrontsize64",
        "-target-feature", "+cumode",       
        "-fcuda-is-device",
        "-I/opt/rocm/include",
        "-O3",
        "-S",
        "-emit-llvm",
        "a.c",
        "-o", "a.ll"
    };
    auto invocation = std::make_shared<CompilerInvocation>();
    CompilerInvocation::CreateFromArgs(*invocation, 
        ArrayRef<const char*>(args).slice(1), 
        diags);
    Clang->setInvocation(std::move(invocation));
    Clang->createDiagnostics();
    bool success = ExecuteCompilerInvocation(Clang.get());
    return 0;
}
