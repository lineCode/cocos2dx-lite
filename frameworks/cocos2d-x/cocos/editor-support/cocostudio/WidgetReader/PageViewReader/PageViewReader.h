
#include "base/ccConfig.h"
#if CC_USE_CCS > 0

/****************************************************************************
 Copyright (c) 2014 cocos2d-x.org
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __TestCpp__PageViewReader__
#define __TestCpp__PageViewReader__

#include "editor-support/cocostudio/WidgetReader/LayoutReader/LayoutReader.h"
#include "editor-support/cocostudio/CocosStudioExport.h"

namespace cocostudio
{
    class CC_STUDIO_DLL PageViewReader : public LayoutReader
    {
        DECLARE_CLASS_NODE_READER_INFO
        
    public:
        PageViewReader();
        virtual ~PageViewReader();
        
        static PageViewReader* getInstance();
        /** @deprecated Use method destroyInstance() instead */
        CC_DEPRECATED_ATTRIBUTE static void purge();
        static void destroyInstance();
        
        virtual void setPropsFromJsonDictionary(cocos2d::ui::Widget* widget, const rapidjson::Value& options);
        virtual void setPropsFromBinary(cocos2d::ui::Widget* widget, CocoLoader* cocoLoader,  stExpCocoNode* cocoNode) ;        
        flatbuffers::Offset<flatbuffers::Table> createOptionsWithFlatBuffers(const tinyxml2::XMLElement* objectData,
                                                                             flatbuffers::FlatBufferBuilder* builder);
        void setPropsWithFlatBuffers(cocos2d::Node* node, const flatbuffers::Table* pageViewOptions);
        cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* pageViewOptions);
        
        int getResourceType(std::string key);
        
    };
}

#endif /* defined(__TestCpp__PageViewReader__) */

#endif // CC_USE_CCS