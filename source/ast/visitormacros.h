#pragma once

//Macro for parametrized visitor accept
#define VISITOR_ACCEPT(BaseVisitor) public: \
    virtual void* accept(const BaseVisitor * v, void * d = nullptr) const { return v->visit(this, d);}

#define VISITOR_VISIT(_CLASS_) public: \
    class _CLASS_; \
virtual void *visit(const _CLASS_ * node, void *data = nullptr) const = 0
