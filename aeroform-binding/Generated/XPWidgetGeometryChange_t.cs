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

public class XPWidgetGeometryChange_t : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal XPWidgetGeometryChange_t(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(XPWidgetGeometryChange_t obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(XPWidgetGeometryChange_t obj) {
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

  ~XPWidgetGeometryChange_t() {
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
          XPlaneWrappersPINVOKE.delete_XPWidgetGeometryChange_t(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public int dx {
    set {
      XPlaneWrappersPINVOKE.XPWidgetGeometryChange_t_dx_set(swigCPtr, value);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      int ret = XPlaneWrappersPINVOKE.XPWidgetGeometryChange_t_dx_get(swigCPtr);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public int dy {
    set {
      XPlaneWrappersPINVOKE.XPWidgetGeometryChange_t_dy_set(swigCPtr, value);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      int ret = XPlaneWrappersPINVOKE.XPWidgetGeometryChange_t_dy_get(swigCPtr);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public int dwidth {
    set {
      XPlaneWrappersPINVOKE.XPWidgetGeometryChange_t_dwidth_set(swigCPtr, value);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      int ret = XPlaneWrappersPINVOKE.XPWidgetGeometryChange_t_dwidth_get(swigCPtr);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public int dheight {
    set {
      XPlaneWrappersPINVOKE.XPWidgetGeometryChange_t_dheight_set(swigCPtr, value);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      int ret = XPlaneWrappersPINVOKE.XPWidgetGeometryChange_t_dheight_get(swigCPtr);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public XPWidgetGeometryChange_t() : this(XPlaneWrappersPINVOKE.new_XPWidgetGeometryChange_t(), true) {
    if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
  }

}

}