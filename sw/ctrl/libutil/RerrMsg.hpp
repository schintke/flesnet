// $Id: RerrMsg.hpp 20 2013-08-10 16:42:54Z mueller $
//
// Copyright 2011-2013 by Walter F.J. Mueller <W.F.J.Mueller@gsi.de>
//
// This program is free software; you may redistribute and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 2, or at your option any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY, without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for complete details.
// 
// Imported Rev 493/474 1.2 from Retro -> CbmNet
// ---------------------------------------------------------------------------


/*!
  \file
  \version $Id: RerrMsg.hpp 20 2013-08-10 16:42:54Z mueller $
  \brief   Declaration of class RerrMsg.
*/

#ifndef included_CbmNet_RerrMsg
#define included_CbmNet_RerrMsg 1

#include <string>
#include <ostream>

namespace CbmNet {

  class RerrMsg {
    public:
                    RerrMsg();
                    RerrMsg(const RerrMsg& rhs);
                    RerrMsg(const std::string& meth, const std::string& text);
                    RerrMsg(const std::string& meth, const std::string& text,
                            int errnum);
                    ~RerrMsg();

      void          Init(const std::string& meth, const std::string& text);
      void          InitErrno(const std::string& meth, 
                              const std::string& text, int errnum);
      void          InitPrintf(const std::string& meth, 
                               const char* format, ...);

      void          SetMeth(const std::string& meth);
      void          SetText(const std::string& text);

      void          Prepend(const std::string& meth);
      void          Append(const std::string& text);
      void          AppendErrno(int errnum);
      void          AppendPrintf(const char* format, ...);

      const std::string& Meth() const;
      const std::string& Text() const;
      std::string   Message() const;

      void          Swap(RerrMsg& rhs);

      RerrMsg&      operator=(const RerrMsg& rhs);
                    operator std::string() const;

    protected:
      std::string   fMeth;                  //!< originating method
      std::string   fText;                  //!< message text
  };

  std::ostream&	    operator<<(std::ostream& os, const RerrMsg& obj);

} // end namespace CbmNet

#include "RerrMsg.ipp"

#endif
