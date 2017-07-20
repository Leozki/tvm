/*!
 *  Copyright (c) 2017 by Contributors
 * \file target_info.h
 * \brief Various information about target.
 */
#ifndef TVM_TARGET_INFO_H_
#define TVM_TARGET_INFO_H_

#include "./base.h"
#include "./expr.h"

namespace tvm {

/*!
 * \brief Memory information of special memory region.
 *  Use MemoryInfo as its container type
 */
struct MemoryInfoNode : public Node {
  /*! \brief The addressable unit */
  int unit_bits;
  /*! \brief Maximum number of bits supported in the memory */
  int max_num_bits;
  /*! \brief maximum number of bits to be used in simd op */
  int max_simd_bits;

  void VisitAttrs(AttrVisitor* v) final {
    v->Visit("unit_bits", &unit_bits);
    v->Visit("max_num_bits", &max_num_bits);
    v->Visit("max_simd_bits", &max_simd_bits);
  }

  static constexpr const char* _type_key = "MemoryInfo";
  TVM_DECLARE_NODE_TYPE_INFO(MemoryInfoNode, Node);
};

/*! \brief Defines memory info */
TVM_DEFINE_NODE_REF(MemoryInfo, MemoryInfoNode);

}  // namespace tvm
#endif  // TVM_TARGET_INFO_H_
