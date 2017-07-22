package simple;

import com.maxeler.maxcompiler.v2.build.EngineParameters;
import com.maxeler.maxcompiler.v2.kernelcompiler.Kernel;
import com.maxeler.maxcompiler.v2.managers.standard.Manager;
import com.maxeler.maxcompiler.v2.managers.standard.Manager.IOType;


class SimpleKernel extends Kernel {
  SimpleKernel(KernelParameters parameters) {
    super(parameters);

    // Input
    DFEVar x = io.input("x", dfeFloat(8, 24));

    // Expression to be calculated
    DFEVar result = x*x + x;

    // Output
    io.output("y", result, dfeFloat(8, 24));
  }
}
