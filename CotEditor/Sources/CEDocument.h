/*
 ==============================================================================
 CEDocument
 
 CotEditor
 http://coteditor.com
 
 Created on 2004-12-08 by nakamuxu
 encoding="UTF-8"
 ------------------------------------------------------------------------------
 
 © 2004-2007 nakamuxu
 © 2014-2015 1024jp
 
 This program is free software; you can redistribute it and/or modify it under
 the terms of the GNU General Public License as published by the Free Software
 Foundation; either version 2 of the License, or (at your option) any later
 version.
 
 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License along with
 this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 Place - Suite 330, Boston, MA  02111-1307, USA.
 
 ==============================================================================
 */

@import Cocoa;
#import "CEWindowController.h"
#import "CETextSelection.h"
#import "CEEditorWrapper.h"
#import "NSString+CENewLine.h"


@class CEEditorWrapper;
@class CEWindowController;


// Incompatible chars listController key
extern NSString *const CEIncompatibleLineNumberKey;
extern NSString *const CEIncompatibleRangeKey;
extern NSString *const CEIncompatibleCharKey;
extern NSString *const CEIncompatibleConvertedCharKey;


@interface CEDocument : NSDocument

@property (nonatomic) CEEditorWrapper *editor;

// readonly properties
@property (readonly, nonatomic) CEWindowController *windowController;
@property (readonly, nonatomic) CETextSelection *selection;
@property (readonly, nonatomic) NSStringEncoding encoding;
@property (readonly, nonatomic) CENewLineType lineEnding;
@property (readonly, nonatomic, copy) NSDictionary *fileAttributes;
@property (readonly, nonatomic, getter=isWritable) BOOL writable;


#pragma mark - Public Methods

/// Return whole string in the current text view which document's line endings are already applied to.  (Note: The internal string (e.g. in text storage) has always LF for its line ending.)
- (NSString *)stringForSave;

- (void)setStringToEditor;

// string encoding
- (NSString *)currentIANACharSetName;
- (NSArray *)findCharsIncompatibleWithEncoding:(NSStringEncoding)encoding;
- (BOOL)reinterpretWithEncoding:(NSStringEncoding)encoding;
- (BOOL)doSetEncoding:(NSStringEncoding)encoding updateDocument:(BOOL)updateDocument askLossy:(BOOL)askLossy lossy:(BOOL)lossy asActionName:(NSString *)actionName;

// line ending
- (void)doSetLineEnding:(CENewLineType)lineEnding;

// syntax style
- (void)doSetSyntaxStyle:(NSString *)name;


#pragma mark Action Messages

- (IBAction)changeLineEndingToLF:(id)sender;
- (IBAction)changeLineEndingToCR:(id)sender;
- (IBAction)changeLineEndingToCRLF:(id)sender;
- (IBAction)changeLineEnding:(id)sender;
- (IBAction)changeEncoding:(id)sender;
- (IBAction)changeTheme:(id)sender;
- (IBAction)changeSyntaxStyle:(id)sender;
- (IBAction)insertIANACharSetName:(id)sender;
- (IBAction)insertIANACharSetNameWithCharset:(id)sender;
- (IBAction)insertIANACharSetNameWithEncoding:(id)sender;

@end
