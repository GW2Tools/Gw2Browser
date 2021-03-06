/* \file       Readers/asndMP3Reader.cpp
*  \brief      Contains the definition of the asnd MP3 reader class.
*  \author     Khral Steelforge
*/

/*
Copyright (C) 2014 Khral Steelforge <https://github.com/kytulendu>

This file is part of Gw2Browser.

Gw2Browser is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "stdafx.h"

#include "asndMP3Reader.h"

namespace gw2b {

    asndMP3Reader::asndMP3Reader( const Array<byte>& p_data, DatFile& p_datFile, ANetFileType p_fileType )
        : FileReader( p_data, p_datFile, p_fileType ) {
    }

    asndMP3Reader::~asndMP3Reader( ) {
    }

    Array<byte> asndMP3Reader::getMP3Data( ) const {
        auto asnd = m_data;
        int size = m_data.GetSize( );

        Array<byte> outputArray( size - 36 );

#pragma omp parallel for
        // skip first 36 byte
        for ( int i = 36; i < size; i++ ) {
            ::memcpy( &outputArray[i - 36], &asnd[i], sizeof( asnd[i] ) );
        }

        return outputArray;
    }

}; // namespace gw2b
