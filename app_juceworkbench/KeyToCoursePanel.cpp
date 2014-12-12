/*
 Copyright 2012-2014 Eigenlabs Ltd.  http://www.eigenlabs.com

 This file is part of EigenD.

 EigenD is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 EigenD is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with EigenD.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "KeyToCoursePanel.h"


KeyToCoursePanel::KeyToCoursePanel (Atom* atom, String mapping, Component* editor)
    : atom_(atom), mapping_(mapping), editor_(editor)
{

    setSize (370, 1000);

    doDisplayMapping(mapping);
}

KeyToCoursePanel::~KeyToCoursePanel()
{
}

void KeyToCoursePanel::paint (Graphics& g)
{
}

void KeyToCoursePanel::resized()
{
}

void KeyToCoursePanel::addElement()
{
    XYToZComponent* element=new XYToZComponent(0,elements_.size()*24);
    elements_.push_back(element);
    addAndMakeVisible(element);
    setSize(370,elements_.size()*24);
    checkRevertable();
}

void KeyToCoursePanel::removeElement(XYToZComponent* element)
{
    for(std::list<XYToZComponent*>::iterator i=elements_.begin();i!=elements_.end();++i)
    {
        (*i)->removing=true;
    }

    removeChildComponent(element);
    elements_.remove(element);

    int count=0;
    for(std::list<XYToZComponent*>::const_iterator i=elements_.begin();i!=elements_.end();++i)
    {
        (*i)->setTopLeftPosition(0,count*24);
        count++;
    }
    delete element;
    setSize(370,elements_.size()*24);
    updateMapping();
    checkRevertable();
}

void KeyToCoursePanel::updateMapping()
{
    mapping_=makeMappingString();
    atom_->set_value(mapping_);
}

String KeyToCoursePanel::makeMappingString()
{
    String mapping="[";
    for(std::list<XYToZComponent*>::iterator i=elements_.begin();i!=elements_.end();++i)
    {
        //if(((*i)->isEmpty())==false)
        if((*i)->isValid())
        {
            mapping=mapping+(*i)->makeMappingString();
            mapping=mapping+",";
        }
    }
    mapping=mapping.upToLastOccurrenceOf(",",false,true)+"]";
    return mapping;
}

String KeyToCoursePanel::makeDisplayedMappingString()
{
    String mapping="[";
    for(std::list<XYToZComponent*>::iterator i=elements_.begin();i!=elements_.end();++i)
    {
            mapping=mapping+(*i)->makeMappingString();
            mapping=mapping+",";
    }
    mapping=mapping.upToLastOccurrenceOf(",",false,true)+"]";
    return mapping;
}


void KeyToCoursePanel::checkRevertable()
{
    String mapping=makeDisplayedMappingString();

    if(!(mapping.equalsIgnoreCase(mapping_)))
    {
        //std::cout<<"Mapping editor is revertable"<<std::endl;
        editor_->postCommandMessage(1);
    }
    else
    {
        //std::cout<<"Mapping editor is not revertable"<<std::endl;
        editor_->postCommandMessage(0);
    }
}

void KeyToCoursePanel::clearMapping()
{
    mapping_=("[]");
    doDisplayMapping(mapping_);
    atom_->set_value(mapping_);
}

void KeyToCoursePanel::doDisplayMapping(String mapping)
{
    for(std::list<XYToZComponent*>::iterator i=elements_.begin();i!=elements_.end();++i)
    {
        (*i)->removing=true;
    }

    elements_.clear();
    deleteAllChildren();
    if(mapping.equalsIgnoreCase("[]"))
    {
        elements_.push_back(new XYToZComponent(0,0));
        setSize(370,elements_.size()*24);
        for(std::list<XYToZComponent*>::const_iterator i=elements_.begin();i!=elements_.end();++i)
        {
            addAndMakeVisible(*i);
        }
    }
    else
    {
        String s=mapping.removeCharacters("[]");
        while( s.isNotEmpty())
        {
            String xin=s.upToFirstOccurrenceOf(",",false,false);
            s=s.fromFirstOccurrenceOf(",",false,false);
            String yin=s.upToFirstOccurrenceOf(",",false,false);
            s=s.fromFirstOccurrenceOf(",",false,false);

            String zout=s.upToFirstOccurrenceOf(",",false,false);
            s=s.fromFirstOccurrenceOf(",",false,false);

            XYToZComponent* element=new XYToZComponent(0,elements_.size()*24);
            element->setInputValues(xin,yin);
            element->setOutputValue(zout);
            elements_.push_back(element);
            addAndMakeVisible(element);
            setSize(370,elements_.size()*24);
        }
    }
    editor_->postCommandMessage(0);

}

void KeyToCoursePanel::displayMapping(String mapping)
{
    std::cout<<"KeyToCoursePanel:displayMapping displayedMapping="<<std::string(mapping_.toUTF8())<<" eigend mapping="<<std::string(mapping.toUTF8())<<std::endl;
    if (!mapping.equalsIgnoreCase(mapping_)) 
    {
        doDisplayMapping(mapping);
    }
}

void KeyToCoursePanel::revertMapping(String mapping)
{
    std::cout<<"KeyToCoursePanel:revertMapping displayedMapping="<<std::string(makeDisplayedMappingString().toUTF8())<<" eigend mapping="<<std::string(mapping.toUTF8())<<std::endl;
    if (!mapping.equalsIgnoreCase(makeDisplayedMappingString())) 
    {
        doDisplayMapping(mapping);
    }
}
