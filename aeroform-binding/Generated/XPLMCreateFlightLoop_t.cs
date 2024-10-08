//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------

namespace Aeroform.Unmanaged.XPLMBindings {

public class XPLMCreateFlightLoop_t : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal XPLMCreateFlightLoop_t(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(XPLMCreateFlightLoop_t obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(XPLMCreateFlightLoop_t obj) {
    if (obj != null) {
      if (!obj.swigCMemOwn)
        throw new global::System.ApplicationException("Cannot release ownership as memory is not owned");
      global::System.Runtime.InteropServices.HandleRef ptr = obj.swigCPtr;
      obj.swigCMemOwn = false;
      obj.Dispose();
      return ptr;
    } else {
      return new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
    }
  }

  ~XPLMCreateFlightLoop_t() {
    Dispose(false);
  }

  public void Dispose() {
    Dispose(true);
    global::System.GC.SuppressFinalize(this);
  }

  protected virtual void Dispose(bool disposing) {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          XPlaneWrappersPINVOKE.delete_XPLMCreateFlightLoop_t(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public int structSize {
    set {
      XPlaneWrappersPINVOKE.XPLMCreateFlightLoop_t_structSize_set(swigCPtr, value);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      int ret = XPlaneWrappersPINVOKE.XPLMCreateFlightLoop_t_structSize_get(swigCPtr);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public int phase {
    set {
      XPlaneWrappersPINVOKE.XPLMCreateFlightLoop_t_phase_set(swigCPtr, value);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      int ret = XPlaneWrappersPINVOKE.XPLMCreateFlightLoop_t_phase_get(swigCPtr);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public SWIGTYPE_p_f_float_float_int_p_void__float callbackFunc {
    set {
      XPlaneWrappersPINVOKE.XPLMCreateFlightLoop_t_callbackFunc_set(swigCPtr, SWIGTYPE_p_f_float_float_int_p_void__float.getCPtr(value));
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      global::System.IntPtr cPtr = XPlaneWrappersPINVOKE.XPLMCreateFlightLoop_t_callbackFunc_get(swigCPtr);
      SWIGTYPE_p_f_float_float_int_p_void__float ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_f_float_float_int_p_void__float(cPtr, false);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public SWIGTYPE_p_void refcon {
    set {
      XPlaneWrappersPINVOKE.XPLMCreateFlightLoop_t_refcon_set(swigCPtr, SWIGTYPE_p_void.getCPtr(value));
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      global::System.IntPtr cPtr = XPlaneWrappersPINVOKE.XPLMCreateFlightLoop_t_refcon_get(swigCPtr);
      SWIGTYPE_p_void ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_void(cPtr, false);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public XPLMCreateFlightLoop_t() : this(XPlaneWrappersPINVOKE.new_XPLMCreateFlightLoop_t(), true) {
    if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
  }

}

}