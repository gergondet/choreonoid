/**
   @author Shin'ichiro Nakaoka
*/

#ifndef CNOID_BASE_SUB_PROJECT_ITEM_H
#define CNOID_BASE_SUB_PROJECT_ITEM_H

#include "Item.h"
#include "exportdecl.h"

namespace cnoid {

class SubProjectItemImpl;

class CNOID_EXPORT SubProjectItem : public Item
{
public:
    static void initializeClass(ExtensionManager* ext);
        
    SubProjectItem();
    SubProjectItem(const SubProjectItem& org);
    virtual ~SubProjectItem();

    bool loadSubProject(const std::string& filename);
    bool saveSubProject(const std::string& filename);
    bool isSavingSubProject() const;

protected:
    virtual Item* doDuplicate() const override;
    virtual void onConnectedToRoot() override;
    virtual void doPutProperties(PutPropertyFunction& putProperty) override;
    virtual bool store(Archive& archive) override;
    virtual bool restore(const Archive& archive) override;

private:
    SubProjectItemImpl* impl;
};

typedef ref_ptr<SubProjectItem> SubProjectItemPtr;
}

#endif
