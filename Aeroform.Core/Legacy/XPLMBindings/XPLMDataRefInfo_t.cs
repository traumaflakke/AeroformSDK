//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------

namespace Aeroform.Core.Legacy.XPLMBindings {

public class XPLMDataRefInfo_t : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal XPLMDataRefInfo_t(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(XPLMDataRefInfo_t obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(XPLMDataRefInfo_t obj) {
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

  ~XPLMDataRefInfo_t() {
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
          XPlaneWrappersPINVOKE.delete_XPLMDataRefInfo_t(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public int structSize {
    set {
      XPlaneWrappersPINVOKE.XPLMDataRefInfo_t_structSize_set(swigCPtr, value);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      int ret = XPlaneWrappersPINVOKE.XPLMDataRefInfo_t_structSize_get(swigCPtr);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public string name {
    set {
      XPlaneWrappersPINVOKE.XPLMDataRefInfo_t_name_set(swigCPtr, value);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      string ret = XPlaneWrappersPINVOKE.XPLMDataRefInfo_t_name_get(swigCPtr);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public int type {
    set {
      XPlaneWrappersPINVOKE.XPLMDataRefInfo_t_type_set(swigCPtr, value);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      int ret = XPlaneWrappersPINVOKE.XPLMDataRefInfo_t_type_get(swigCPtr);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public int writable {
    set {
      XPlaneWrappersPINVOKE.XPLMDataRefInfo_t_writable_set(swigCPtr, value);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      int ret = XPlaneWrappersPINVOKE.XPLMDataRefInfo_t_writable_get(swigCPtr);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public int owner {
    set {
      XPlaneWrappersPINVOKE.XPLMDataRefInfo_t_owner_set(swigCPtr, value);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      int ret = XPlaneWrappersPINVOKE.XPLMDataRefInfo_t_owner_get(swigCPtr);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public XPLMDataRefInfo_t() : this(XPlaneWrappersPINVOKE.new_XPLMDataRefInfo_t(), true) {
    if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
  }

}

}
